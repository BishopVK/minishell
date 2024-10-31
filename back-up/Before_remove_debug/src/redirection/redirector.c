/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:01:59 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 14:30:43 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_restant_fds(t_execution *exe_command, t_mini *mini, int i)
{
	t_execution	*iter_exe;

	if (i == 0)
	{
		close(mini->standard_fds[0]);
		close(mini->standard_fds[1]);
	}
	iter_exe = exe_command;
	while (iter_exe != NULL)
	{
		if (iter_exe->n_command != exe_command->n_command)
		{
			close_fds(iter_exe);
		}
		iter_exe = iter_exe->next;
	}
}

int	syntax_errors(int i, char *redir_content, t_mini *mini)
{
	if (i == 1)
		ft_dprintf(2, "minishell: syntax error near unexpected token `|'\n");
	else if (i == 2)
		ft_dprintf(2,
			"minishell: syntax error near unexpected token `newline'\n");
	else if (i == 3)
		ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n",
			redir_content);
	else if (i == 4)
		ft_dprintf(2,
			"minishell: syntax error near unexpected token `|'\n");
	ft_export_env("?=2", mini);
	return (ERR);
}

int	errors_and_n_commands(t_params *iter, t_mini *mini)
{
	if (iter->type == '|')
		return (syntax_errors(1, iter->content, mini));
	while (iter != NULL)
	{
		if (iter->type == INFILE || iter->type == OUTFILE
			|| iter->type == HERE_DOC || iter->type == APPEND)
		{
			if (iter->next == NULL)
				return (syntax_errors(2, iter->content, mini));
			if (iter->next->type == PIPE)
				return (syntax_errors(1, iter->content, mini));
			if (iter->next->type == INFILE || iter->next->type == HERE_DOC
				|| iter->next->type == OUTFILE || iter->next->type == APPEND)
				return (syntax_errors(3, iter->next->content, mini));
		}
		if (iter->type == PIPE)
		{
			if (iter->next == NULL)
				return (syntax_errors(4, iter->content, mini));
			mini->n_commands++;
		}
		iter = iter->next;
	}
	printf("DB: the number of commands is: %i\n", mini->n_commands);
	return (0);
}

int	if_error_in_here_doc(t_args *args, int *here_doc_fds, int n_here_doc)
{
	t_params	*iter;

	iter = args->params;
	while (iter != NULL)
	{
		if (iter->type == HERE_DOC)
		{
			if (here_doc_fds[n_here_doc] < 0)
			{
				while (--n_here_doc >= 0)
					if (n_here_doc >= 0)
						close(here_doc_fds[n_here_doc]);
				if (here_doc_fds)
				{
					free(here_doc_fds);
					here_doc_fds = NULL;
				}
				ft_export_env("?=130", args->mini);
				return (1);
			}
			n_here_doc++;
		}
		iter = iter->next;
	}
	return (0);
}

int	fill_exe_redirections(t_params *iter_params, t_execution *iter_exe,
	t_args *args, t_mini *mini)
{
	int			*here_doc_fds;

	here_doc_fds = get_here_doc(iter_params, args, 0);
	if (if_error_in_here_doc(args, here_doc_fds, 0) == 1)
		return (ERR);
	while (iter_params)
	{
		if (iter_params->type == INFILE)
			fill_infile(iter_params->next, iter_exe, mini);
		else if (iter_params->type == HERE_DOC)
			fill_here_doc(here_doc_fds[mini->n_here_docs], iter_exe, mini);
		else if (iter_params->type == APPEND)
			fill_append(iter_params->next, iter_exe, mini);
		else if (iter_params->type == OUTFILE)
			fill_outfile(iter_params->next, iter_exe, mini);
		else if (iter_params->type == PIPE)
		{
			fill_pipe(iter_exe);
			iter_exe = iter_exe->next;
		}
		iter_params = iter_params->next;
	}
	if (here_doc_fds != NULL)
		free(here_doc_fds);
	return (0);
}
