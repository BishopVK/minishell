/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:12:17 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/25 19:51:14 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_built_ins(char **command, t_execution *iter_exe,
	t_mini *mini, t_args *args)
{
	int		len;
	int		exit_status;

	exit_status = 0;
	dup_redirections(iter_exe);
	if (iter_exe->n_command < mini->n_commands)
		close_restant_fds(iter_exe, mini, 0);
	else
		close_restant_fds(iter_exe, mini, 1);
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

pid_t	set_pids(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	create_fork(t_execution *iter_exe, t_mini *mini, t_args *args,
	int exit_status)
{
	pid_t	pid;

	pid = set_pids();
	if (pid == 0)
	{
		free (args->last_history);
		signal(SIGQUIT, SIG_DFL);
		if (be_built_ins(iter_exe->command) == 1)
		{
			exit_status = check_built_ins(iter_exe->command,
					iter_exe, mini, args);
			close(mini->standard_fds[0]);
			close(mini->standard_fds[1]);
			exe_struct_free(mini);
			exit (exit_status);
		}
		else
		{
			exit_status = execute(iter_exe, mini, args);
			exit (exit_status);
		}
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	return (pid);
}

void	close_fds(t_execution *iter_exe)
{
	if (iter_exe->inf_pipe > 0)
	{
		close(iter_exe->inf_pipe);
	}
	if (iter_exe->outf_pipe > 0 && iter_exe->outf_pipe != 1)
	{
		close(iter_exe->outf_pipe);
	}
}
