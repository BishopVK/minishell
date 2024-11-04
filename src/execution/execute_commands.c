/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:50:09 by isainz-r          #+#    #+#             */
/*   Updated: 2024/11/04 12:45:57 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_last_env(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->env)
	{
		while (mini->env[i])
		{
			free(mini->env[i]);
			i++;
		}
		free(mini->env);
		mini->env = NULL;
	}
}

void	create_env_matrix(t_mini *mini)
{
	char	*temp;
	char	*var_temp;
	char	*env_one_line;

	free_last_env(mini);
	env_one_line = NULL;
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		temp = ft_strjoin(mini->env_iter->variable, "=");
		var_temp = ft_strjoin(temp, mini->env_iter->content);
		free(temp);
		temp = ft_strjoin(var_temp, "\n");
		free(var_temp);
		var_temp = ft_strjoin(env_one_line, temp);
		free(temp);
		if (env_one_line)
			free(env_one_line);
		env_one_line = var_temp;
		mini->env_iter = mini->env_iter->next;
	}
	mini->env = ft_split(env_one_line, '\n');
	free(env_one_line);
}

void	free_and_close_all(t_mini *mini)
{
	close_inf_outf(mini);
	close(mini->standard_fds[0]);
	close(mini->standard_fds[1]);
	free(mini->user_prompt);
	ft_lstclear(&mini->here_doc_files, free);
	free_last_env(mini);
	exe_struct_free(mini);
	free_env(mini);
}

int	other_error(t_execution *iter_exe, t_mini *mini)
{
	if (ft_strchr(iter_exe->command[0], '/') != 0)
	{
		if (access(iter_exe->command[0], F_OK) != 0)
		{
			ft_dprintf(2, "minishell: %s: No such file or directory\n",
				iter_exe->command[0]);
			return (0);
		}
		ft_dprintf(2, "minishell: %s: Is a directory or permission denied\n",
			iter_exe->command[0]);
		free_and_close_all(mini);
		return (1);
	}
	ft_dprintf(2, "minishell: %s: command not found\n", iter_exe->command[0]);
	return (0);
}

int	execute(t_execution *iter_exe, t_mini *mini, t_args *args)
{
	char	*path_mid;
	char	*path_command;

	create_env_matrix(args->mini);
	dup_redirections(iter_exe);
	path_mid = NULL;
	path_command = get_path_command(0, iter_exe->command, mini->env, path_mid);
	if (path_command)
	{
		if (access(path_command, X_OK) == 0)
		{
			close_restant_fds(mini->exe_command, mini, 0);
			execve(path_command, iter_exe->command, mini->env);
		}
		free(path_command);
		path_command = NULL;
	}
	if (other_error(iter_exe, mini) == 1)
		return (126);
	free_and_close_all(mini);
	return (127);
}
