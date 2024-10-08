/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_executing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:13:15 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/08 21:24:27 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_built_ins(char **command, t_execution *iter_exe,
	t_mini *mini, t_args *args)
{
	int		len;
	int		exit_status;

	exit_status = 0;
	dup_redirections(iter_exe);
	close_restant_fds(iter_exe, mini);
	len = ft_strlen(command[0]);
	if (ft_strncmp(command[0], "echo", len) == 0 && len == 4)
		exit_status = ft_built_echo(command);
	else if (ft_strncmp(command[0], "cd", len) == 0 && len == 2)
		exit_status = ft_built_cd(command, mini);
	else if (ft_strncmp(command[0], "pwd", len) == 0 && len == 3)
		exit_status = ft_built_pwd(command, mini);
	else if (ft_strncmp(command[0], "export", len) == 0 && len == 6)
		exit_status = ft_built_export(command, mini);
	else if (ft_strncmp(command[0], "unset", len) == 0 && len == 5)
		exit_status = ft_built_unset(command, mini);
	else if (ft_strncmp(command[0], "env", len) == 0 && len == 3)
		exit_status = ft_built_env(command, mini);
	else if (ft_strncmp(command[0], "exit", len) == 0 && len == 4)
		exit_status = ft_built_exit(args, command);
	return (exit_status);
}

int	be_built_ins(char **command)
{
	int	len;

	len = ft_strlen(command[0]);
	if (ft_strncmp(command[0], "echo", len) == 0 && len == 4)
		return (1);
	else if (ft_strncmp(command[0], "cd", len) == 0 && len == 2)
		return (1);
	else if (ft_strncmp(command[0], "pwd", len) == 0 && len == 3)
		return (1);
	else if (ft_strncmp(command[0], "export", len) == 0 && len == 6)
		return (1);
	else if (ft_strncmp(command[0], "unset", len) == 0 && len == 5)
		return (1);
	else if (ft_strncmp(command[0], "env", len) == 0 && len == 3)
		return (1);
	else if (ft_strncmp(command[0], "exit", len) == 0 && len == 4)
		return (1);
	return (0);
}

void	create_fork(t_execution *iter_exe, t_mini *mini, t_args *args)
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	exit_status = 0;
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		ft_dprintf(2, "DB: (1) exit_status value: %i\n", exit_status);
		if (be_built_ins(iter_exe->command) == 1)
		{
			exit_status = check_built_ins(iter_exe->command,
					iter_exe, mini, args);
			close(mini->standard_fds[0]);
			close(mini->standard_fds[1]);
			ft_dprintf(2, "DB: (2) exit_status value: %i\n", exit_status);
			exit (exit_status);
		}
		else
			execute(iter_exe, mini, args);
	}
}

void	close_fds(t_execution *iter_exe)
{
	if (iter_exe->inf_pipe > 0)
		close(iter_exe->inf_pipe);
	if (iter_exe->outf_pipe > 0 && iter_exe->outf_pipe != 1)
		close(iter_exe->outf_pipe);
}

int	start_executing(t_execution *iter_exe, int status,
	t_mini *mini, t_args *args)
{
	int		exit_status;
	char	*exit_status_itoa;
	char	*exit_status_str;

	exit_status = 0;
	while (iter_exe != NULL)
	{
		if (iter_exe->inf_pipe < 0 || iter_exe->outf_pipe < 0)
		{
			close_fds(iter_exe);
			iter_exe = iter_exe->next;
			continue ;
		}
		if (mini->n_commands == 1)
		{
			if (be_built_ins(iter_exe->command) == 1)
			{
				exit_status = check_built_ins(iter_exe->command, iter_exe,
						mini, args);
				exit_status_itoa = ft_itoa(exit_status);
				exit_status_str = ft_strjoin("?=", exit_status_itoa);
				free(exit_status_itoa);
				ft_export_env(exit_status_str, mini);
				free(exit_status_str);
				// Comprobar si el built-in es exit, y hacer un exit con el valor de return
				ft_dprintf(2, "DB: 1 built-in status value: %i\n", exit_status);
				if (ft_strncmp(iter_exe->command[0], "exit", ft_strlen(iter_exe->command[0])) == 0 && ft_strlen(iter_exe->command[0]) == 4 && exit_status != -1)
				{
					free_at_exit(args);
					exit(exit_status);
				}
				else if ((ft_strncmp(iter_exe->command[0], "exit", ft_strlen(iter_exe->command[0])) == 0 && ft_strlen(iter_exe->command[0]) == 4 && exit_status == -1))
					ft_export_env("?=1", mini);
				return (0);
			}
		}
		create_fork(iter_exe, mini, args);
		//ft_export_env("?=55", mini); //Actualizar para Built-ins y execves
		close_fds(iter_exe);
		iter_exe = iter_exe->next;
	}
	while (waitpid(-1, &status, 0) != -1)
	{
		ft_dprintf(2, "DB: waitpid status value: %i\n", WEXITSTATUS(status));
		continue ;
	}
	exit_status_itoa = ft_itoa(WEXITSTATUS(status));
	exit_status_str = ft_strjoin("?=", exit_status_itoa);
	free(exit_status_itoa);
	ft_export_env(exit_status_str, mini);
	free(exit_status_str);
	//ft_export_env("?=55", mini); //Actualizar para Built-ins y execves
	return (WEXITSTATUS(status));
}
