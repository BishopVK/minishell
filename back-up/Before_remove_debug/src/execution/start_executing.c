/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_executing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:13:15 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 18:26:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	built_in_command(int exit_status, t_execution *iter_exe,
	t_mini *mini, t_args *args)
{
	char	*exit_status_itoa;
	char	*exit_status_str;

	exit_status = check_built_ins(iter_exe->command, iter_exe,
			mini, args);
	exit_status_itoa = ft_itoa(exit_status);
	exit_status_str = ft_strjoin("?=", exit_status_itoa);
	free(exit_status_itoa);
	ft_export_env(exit_status_str, mini);
	free(exit_status_str);
	if (ft_strcmp(iter_exe->command[0], "exit") == 0
		&& ft_strlen(iter_exe->command[0]) == 4)
	{
		if ((exit_status == -1 && iter_exe->command[1]
				&& ft_strcmp(iter_exe->command[1], "-1") != 0)
			|| (iter_exe->command[1] && iter_exe->command[2]
				&& exit_status != 2))
			ft_export_env("?=1", mini);
		else
		{
			free_at_exit(args);
			printf("exit\n"); // REMOVE BEFORE EVALUATIONS
			exit(exit_status);
		}
	}
	return (0);
}

void	set_return_value(int last_status, t_mini *mini)
{
	char	*exit_status_itoa;
	char	*exit_status_str;

	exit_status_itoa = ft_itoa(last_status);
	exit_status_str = ft_strjoin("?=", exit_status_itoa);
	free(exit_status_itoa);
	ft_export_env(exit_status_str, mini);
	free(exit_status_str);
}

void	wait_and_return(int status, pid_t last_pid,
	int *last_status, t_mini *mini)
{
	pid_t		pid;
	t_execution	*iter_exe_cpy;

	iter_exe_cpy = mini->exe_command;
	pid = waitpid(-1, &status, 0);
	while (pid != -1)
	{
		if (pid == last_pid)
			*last_status = WEXITSTATUS(status);
		pid = waitpid(-1, &status, 0);
	}
	set_return_value(*last_status, mini);
	while (iter_exe_cpy != NULL)
	{
		if (ft_strncmp(iter_exe_cpy->command[0], "exit",
				ft_strlen(iter_exe_cpy->command[0])) == 0
			&& ft_strlen(iter_exe_cpy->command[0]) == 4
			&& *last_status == 255 && iter_exe_cpy->command[2] != NULL)
			ft_export_env("?=1", mini);
		iter_exe_cpy = iter_exe_cpy->next;
	}
}

int	check_return_value_one(t_execution *iter_exe, t_mini *mini)
{
	iter_exe = mini->exe_command;
	while (iter_exe->next != NULL)
		iter_exe = iter_exe->next;
	if (iter_exe->inf_pipe < 0 || iter_exe->outf_pipe < 0)
	{
		ft_export_env("?=1", mini);
		return (1);
	}
	return (0);
}

int	start_executing(t_execution *iter_exe, int status,
	t_mini *mini, t_args *args)
{
	int		exit_status;
	pid_t	last_pid;
	int		last_status;

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
			if (be_built_ins(iter_exe->command) == 1)
				return (built_in_command(exit_status, iter_exe, mini, args));
		last_pid = create_fork(iter_exe, mini, args, 0);
		close_fds(iter_exe);
		iter_exe = iter_exe->next;
	}
	wait_and_return(status, last_pid, &last_status, mini);
	if (check_return_value_one(iter_exe, mini) == 1)
		return (1);
	return (last_status);
}
