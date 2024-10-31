/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_red_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:40:54 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 14:30:37 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exe(t_args *args, t_mini *mini)
{
	t_execution	*iter_exe;
	t_params	*iter_params;

	iter_exe = mini->exe_command;
	iter_params = args->params;
	fill_exe(iter_params, iter_exe);
}

int	red(t_args *args, t_mini *mini)
{
	t_params	*iter_params;
	t_execution	*iter_exe;

	iter_params = args->params;
	mini->n_commands = 1;
	if (errors_and_n_commands(iter_params, mini) == ERR)
		return (ERR);
	if (create_execution_struct(mini) == ERR)
		return (ERR);
	iter_params = args->params;
	iter_exe = mini->exe_command;
	if (fill_exe_redirections(iter_params, iter_exe, args, mini) == ERR)
		return (ERR);
	return (0);
}

void	close_inf_outf(t_mini *mini)
{
	t_execution	*iter;
	t_list		*temp_here_doc;

	iter = mini->exe_command;
	while (iter != NULL)
	{
		if (iter->inf_pipe > 0)
		{
			close(iter->inf_pipe);
		}
		if (iter->outf_pipe > 1)
		{
			close(iter->outf_pipe);
		}
		iter = iter->next;
	}
	temp_here_doc = mini->here_doc_files;
	while (temp_here_doc != NULL)
	{
		unlink(temp_here_doc->content);
		temp_here_doc = temp_here_doc->next;
	}
	ft_lstclear(&mini->here_doc_files, free);
	mini->here_doc_files = NULL;
}

void	dup_redirections(t_execution *iter_exe)
{
	if (iter_exe->inf_pipe != 0)
	{
		dup2(iter_exe->inf_pipe, 0);
		close(iter_exe->inf_pipe);
	}
	if (iter_exe->outf_pipe != 1 && iter_exe->outf_pipe != 2)
	{
		dup2(iter_exe->outf_pipe, 1);
		close(iter_exe->outf_pipe);
	}
}

int	new_red_exe(t_args *args, t_mini *mini)
{
	t_execution	*iter;
	int			i; //DB
	int			status;

	if (red(args, mini) == ERR)
		return (ERR);
	exe(args, mini);
	iter = mini->exe_command; //DB
	while (iter != NULL) //DB
	{ //DB
		printf("DB: n_command: %i   inf: %i   outf: %i   type: %i\n",
			iter->n_command, iter->inf_pipe, iter->outf_pipe, iter->type); //DB
		i = 0; //DB
		while (iter->command[i]) //DB
		{ //DB
			printf("DB: command = %s\n", iter->command[i]); //DB
			i++; //DB
		} //DB
		iter = iter->next; //DB
	} //DB
	iter = mini->exe_command;
	status = 0;
	del_params(args);
	free (args->input);
	args->input = NULL;
	start_executing(iter, status, mini, args);
	return (0);
}
