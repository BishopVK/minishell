/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:24:37 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/14 09:25:37 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Cuento con que solo me dan la variable que
// quiere desetear, no el contenido también
static int	ft_to_unset(t_env *prev, char *unset, t_mini *mini)
{
	if (!ft_strncmp(mini->env_iter->variable,
			mini->env_first_node->variable,
			ft_strlen(mini->env_first_node->variable)))
	{
		mini->env_first_node = mini->env_first_node->next;
		free(mini->env_iter->variable);
		free(mini->env_iter->content);
		free(mini->env_iter);
		return (0);
	}
	while (prev != NULL && ft_strncmp(prev->next->variable,
			unset, ft_strlen(unset)))
		prev = prev->next;
	if (mini->env_iter->next)
		prev->next = mini->env_iter->next;
	else
		prev->next = NULL;
	free(mini->env_iter->variable);
	free(mini->env_iter->content);
	free(mini->env_iter);
	return (0);
}

void	ft_unset_env(char *unset, t_mini *mini)
{
	t_env	*prev;

	mini->env_iter = mini->env_first_node;
	if (ft_strcmp(unset, "_") == 0 || ft_strcmp(unset, "?") == 0
		|| ft_strcmp(unset, "PWD") == 0)
		return ;
	while (mini->env_iter != NULL)
	{
		if (!ft_strncmp(unset, mini->env_iter->variable, ft_strlen(unset)))
		{
			prev = mini->env_first_node;
			ft_to_unset(prev, unset, mini);
			return ;
		}
		mini->env_iter = mini->env_iter->next;
	}
}
