/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:17:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/23 20:39:23 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	initialize_structs(t_args *args, t_mini *mini, char **env)
{
	ft_bzero(args, sizeof(t_args));
	ft_bzero(mini, sizeof(t_mini));
	ft_set_env(env, mini);
	args->mini = mini;
	mini->standard_fds[0] = dup(STDIN_FILENO);
	mini->standard_fds[1] = dup(STDOUT_FILENO);
}

void	create_minim_env_vars(t_mini *mini)
{
	char	*cwd;
	char	*join;

	ft_export_env("?=0", mini);
	cwd = getcwd(NULL, 0);
	join = ft_strjoin("PWD=", cwd);
	ft_export_env(join, mini);
	free (cwd);
	free (join);
	if (ft_find_env(mini, "PATH") == NULL)
		ft_export_env(PATH, mini);
}

int	create_prompt(t_mini *mini)
{
	char	*entry;

	if (getenv("USER") == NULL)
		entry = ft_strdup("user@minishell> ");
	else
		entry = ft_strjoin(getenv("USER"), "@minishell> ");
	mini->user_prompt = malloc(ft_strlen(RED) + ft_strlen(BOLD)
			+ ft_strlen(entry) + ft_strlen(RESET) + 1);
	if (!mini->user_prompt)
	{
		ft_dprintf(2, "Error allocating memory\n");
		free_env(mini);
		return (ERR);
	}
	ft_strcpy(mini->user_prompt, RED);
	ft_strlcat(mini->user_prompt, BOLD, ft_strlen(RED) + ft_strlen(BOLD)
		+ ft_strlen(entry) + ft_strlen(RESET) + 1);
	ft_strlcat(mini->user_prompt, entry, ft_strlen(RED) + ft_strlen(BOLD)
		+ ft_strlen(entry) + ft_strlen(RESET) + 1);
	ft_strlcat(mini->user_prompt, RESET, ft_strlen(RED) + ft_strlen(BOLD)
		+ ft_strlen(entry) + ft_strlen(RESET) + 1);
	free (entry);
	return (OK);
}

int	initialize_main_loop(t_mini *mini, t_args *args, int is_piped)
{
	dup2(mini->standard_fds[0], STDIN_FILENO);
	dup2(mini->standard_fds[1], STDOUT_FILENO);
	g_signal_received = 0;
	if (!is_piped)
		args->input = readline(mini->user_prompt);
	else
		args->input = get_next_line(STDIN_FILENO, t_false);
	if (g_signal_received == SIGINT)
	{
		ft_export_env("?=130", mini);
		g_signal_received = 0;
	}
	if (!args->input)
	{
		handle_eof();
		return (ERR);
	}
	return (OK);
}

void	trim_input(t_args *args)
{
	args->input_trimed = ft_strtrim(args->input, " \t\n\r\f\v");
	free(args->input);
	args->input = args->input_trimed;
	args->input_trimed = NULL;
}
