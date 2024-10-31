/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:24:53 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 14:30:35 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_infile(t_params *iter_params, t_execution *iter_exe, t_mini *mini)
{
	if (iter_exe->inf_pipe < 0 || iter_exe->outf_pipe < 0)
	{
		return ;
	}
	if (iter_exe->inf_pipe != 0)
	{
		close (iter_exe->inf_pipe);
	}
	iter_exe->inf_pipe = open(iter_params->content, O_RDONLY);
	if (iter_exe->inf_pipe < 0)
	{
		ft_dprintf(2, "minishell: %s: No such file or directory\n",
			iter_params->content);
		ft_export_env("?=1", mini);
	}
}

void	fill_here_doc(int fd, t_execution *iter_exe, t_mini *mini)
{
	mini->n_here_docs++;
	if (iter_exe->inf_pipe < 0 || iter_exe->outf_pipe < 0)
	{
		close(fd);
		return ;
	}
	if (iter_exe->inf_pipe != 0)
	{
		close(iter_exe->inf_pipe);
	}
	iter_exe->inf_pipe = fd;
	if (iter_exe->inf_pipe < 0)
	{
		ft_dprintf(2, "minishell: Error opening here_doc\n");
		ft_export_env("?=1", mini);
	}
}

void	fill_append(t_params *iter_params, t_execution *iter_exe, t_mini *mini)
{
	if (iter_exe->outf_pipe < 0 || iter_exe->inf_pipe < 0)
	{
		return ;
	}
	if (iter_exe->outf_pipe != 1)
	{
		close(iter_exe->outf_pipe);
	}
	iter_exe->outf_pipe = open(iter_params->content, O_WRONLY | O_CREAT
			| O_APPEND, 0777);
	if (iter_exe->outf_pipe < 0)
	{
		ft_dprintf(2, "minishell: %s: Permission denied\n",
			iter_params->content);
		ft_export_env("?=1", mini);
	}
}

void	fill_outfile(t_params *iter_params, t_execution *iter_exe, t_mini *mini)
{
	if (iter_exe->outf_pipe < 0 || iter_exe->inf_pipe < 0)
	{
		return ;
	}
	if (iter_exe->outf_pipe != 1)
	{
		close(iter_exe->outf_pipe);
	}
	iter_exe->outf_pipe = open(iter_params->content, O_RDWR | O_CREAT
			| O_TRUNC, 0777);
	if (iter_exe->outf_pipe < 0)
	{
		ft_dprintf(2, "minishell: %s: Permission denied\n",
			iter_params->content);
		ft_export_env("?=1", mini);
	}
}

void	fill_pipe(t_execution *iter_exe)
{
	int	pipe_fds[2];

	pipe(pipe_fds);
	if (iter_exe->outf_pipe == 1)
	{
		iter_exe->outf_pipe = pipe_fds[1];
	}
	else if (iter_exe->outf_pipe != 1)
	{
		close(pipe_fds[1]);
	}
	iter_exe = iter_exe->next;
	if (iter_exe->inf_pipe == 0)
	{
		iter_exe->inf_pipe = pipe_fds[0];
	}
	else if (iter_exe->inf_pipe > 0)
	{
		close(pipe_fds[0]);
	}
}
