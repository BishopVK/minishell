/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:03:16 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/20 23:24:43 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_args(char **args, t_mini *mini, int *exit_status)
{
	int	i;
	int	void_arg;

	i = 1;
	void_arg = 0;
	while (args[i])
	{
		if (args[i][0] != '\0')
		{
			if (loop_args(args, mini, &i, exit_status) == -1)
				break ;
		}
		else
		{
			ft_dprintf(2, "minishell: export: `': not a valid identifier\n");
			void_arg++;
		}
		i++;
	}
	if (void_arg != 0)
		*exit_status = 1;
}

static void	print_list(t_mini *mini)
{
	int	i;

	i = 1;
	while (i <= mini->nbr_env_nodes)
	{
		mini->env_iter = mini->env_first_node;
		while (mini->env_iter != NULL )
		{
			if (mini->env_iter->order == i)
			{
				if (ft_strlen(mini->env_iter->variable) == 1
					&& (mini->env_iter->variable[0] == '_'
						|| mini->env_iter->variable[0] == '?'))
					break ;
				else if (mini->env_iter->content)
					printf("declare -x %s=\"%s\"\n", mini->env_iter->variable,
						mini->env_iter->content);
				else
					printf("declare -x %s\n", mini->env_iter->variable);
				break ;
			}
			mini->env_iter = mini->env_iter->next;
		}
		i++;
	}
}

static void	create_nodes_order(t_mini *mini)
{
	t_env	*next_node;
	int		less_quantity;

	mini->env_iter = mini->env_first_node;
	while (mini->env_iter)
	{
		less_quantity = 0;
		next_node = mini->env_first_node;
		while (next_node)
		{
			if (ft_strcmp(mini->env_iter->variable, next_node->variable) > 0)
				less_quantity++;
			next_node = next_node->next;
		}
		mini->env_iter->order = less_quantity + 1;
		mini->env_iter = mini->env_iter->next;
	}
}

static void	count_nodes(t_mini *mini)
{
	mini->nbr_env_nodes = 0;
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		mini->nbr_env_nodes++;
		mini->env_iter->order = 0;
		mini->env_iter = mini->env_iter->next;
	}
}

int	ft_built_export(char **args, t_mini *mini)
{
	int	argc;
	int	exit_status;

	argc = 0;
	exit_status = 0;
	while (args[argc])
		argc++;
	if (argc == 1)
	{
		count_nodes(mini);
		create_nodes_order(mini);
		print_list(mini);
		return (exit_status);
	}
	else
		export_args(args, mini, &exit_status);
	return (exit_status);
}
