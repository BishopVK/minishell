/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:08:04 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/03 22:22:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_built_env(char **args, t_mini *mini)
{
	int	argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc > 1)
		return (ft_dprintf(2, "minishell: env: Args not allowed\n"), 1);
	else
	{
		ft_export_env("_=/usr/bin/env", mini);
		mini->env_iter = mini->env_first_node;
		while (mini->env_iter != NULL)
		{
			if (ft_strcmp(mini->env_iter->variable, "?") == 0)
			{
				mini->env_iter = mini->env_iter->next;
				continue ;
			}
			if (mini->env_iter->content)
				printf("%s=%s\n", mini->env_iter->variable,
					mini->env_iter->content);
			mini->env_iter = mini->env_iter->next;
		}
	}
	return (0);
}
