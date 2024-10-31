/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:42:02 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/14 08:46:30 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_update_existing_node(char *new_env, t_mini *mini,
	char *name, int *equal)
{
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		if (ft_strcmp(name, mini->env_iter->variable) == 0 && *equal == 0)
			return (free(name), OK);
		if (ft_strcmp(name, mini->env_iter->variable) == 0 && *equal != 0)
		{
			free(name);
			free(mini->env_iter->content);
			mini->env_iter->content = ft_substr(new_env, *equal + 1,
					ft_strlen(new_env) - *equal + 1);
			return (OK);
		}
		mini->env_iter = mini->env_iter->next;
	}
	return (ERR);
}

static int	ft_existing_node(char *new_env, t_mini *mini)
{
	int		i;
	int		equal;
	char	*name;

	i = 0;
	equal = 0;
	while (new_env[i])
	{
		if (new_env[i] == '=' && equal == 0)
			equal = i;
		i++;
	}
	if (equal != 0)
		name = ft_substr(new_env, 0, equal);
	else
		name = ft_substr(new_env, 0, ft_strlen(new_env));
	if (ft_update_existing_node(new_env, mini, name, &equal) == OK)
		return (OK);
	return (free(name), ERR);
}

void	ft_export_env(char *new_env, t_mini *mini)
{
	t_env	*new_node;

	if (ft_existing_node(new_env, mini) == OK)
		return ;
	new_node = env_new(new_env);
	if (!new_node)
		return (free_env(mini), (void)0);
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		if ((ft_strcmp(new_node->variable, mini->env_iter->variable) == 0)
			&& new_node->content)
		{
			free(mini->env_iter->content);
			mini->env_iter->content = ft_strdup(new_node->content);
			free(new_node->content);
			free(new_node->variable);
			free(new_node);
			return ;
		}
		mini->env_iter = mini->env_iter->next;
	}
	add_back_env(new_node, mini);
}

char	*ft_get_env(char *to_expand, t_mini *mini)
{
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		if (!ft_strncmp(to_expand, mini->env_iter->variable,
				ft_strlen(mini->env_iter->variable)))
			return (mini->env_iter->content);
		mini->env_iter = mini->env_iter->next;
	}
	return (0);
}

int	ft_set_env(char **env, t_mini *mini)
{
	t_env	*node;
	int		i;

	i = 0;
	mini->env_first_node = NULL;
	while (env[i])
	{
		node = env_new(env[i]);
		if (!node)
			free_env(mini);
		i++;
		add_back_env(node, mini);
	}
	return (0);
}
