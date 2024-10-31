/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:39:43 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 14:25:37 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_execution	*exe_struct_new(int i)
{
	t_execution	*node;

	node = (t_execution *)malloc(sizeof(t_execution));
	if (!node)
		return (NULL);
	node->n_command = i;
	node->command = NULL;
	node->type = PARAMS;
	node->inf_pipe = 0;
	node->outf_pipe = 1;
	node->next = NULL;
	return (node);
}

void	exe_struct_free(t_mini *mini)
{
	t_execution	*next;
	int			i;

	if (mini->exe_command)
	{
		while (mini->exe_command != NULL)
		{
			next = mini->exe_command->next;
			i = 0;
			if (mini->exe_command->command)
			{
				while (mini->exe_command->command[i])
				{
					free(mini->exe_command->command[i]);
					i++;
				}
				free(mini->exe_command->command);
				mini->exe_command->command = NULL;
			}
			free(mini->exe_command);
			mini->exe_command = next;
		}
	}
	mini->exe_command = NULL;
}

void	exe_struct_add_back(t_execution *node, t_mini *mini)
{
	t_execution	*iter;

	if (!mini->exe_command)
	{
		mini->exe_command = node;
		return ;
	}
	iter = mini->exe_command;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = node;
}

int	create_execution_struct(t_mini *mini)
{
	int			i;
	t_execution	*node;

	i = 1;
	mini->exe_command = NULL;
	while (i <= mini->n_commands)
	{
		node = exe_struct_new(i);
		if (!node)
		{
			exe_struct_free(mini);
			return (ERR);
		}
		exe_struct_add_back(node, mini);
		i++;
	}
	return (0);
}
