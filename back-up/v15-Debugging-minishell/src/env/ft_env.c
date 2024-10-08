/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:42:02 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/01 15:47:18 by danjimen &       ###   ########.fr       */
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
	if (ft_strcmp(unset, "_") == 0 || ft_strcmp(unset, "?") == 0)
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

int	ft_existing_node(char *new_env, t_mini *mini)
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
	mini->env_iter = mini->env_first_node;
	while (mini->env_iter != NULL)
	{
		if (ft_strcmp(name, mini->env_iter->variable) == 0 && equal == 0)
		{
			free(name);
			return (OK);
		}
		if (ft_strcmp(name, mini->env_iter->variable) == 0 && equal != 0)
		{
			free(name);
			free(mini->env_iter->content);
			mini->env_iter->content = ft_substr(new_env, equal + 1, ft_strlen(new_env) - equal + 1);
			return (OK);
		}
		mini->env_iter = mini->env_iter->next;
	}
	free(name);
	return (ERR);
}

void	ft_export_env(char *new_env, t_mini *mini)
{
	t_env	*new_node;

	if (ft_existing_node(new_env, mini) == OK)
		return ;
	// SERÍA INTERESANTE COMPROBAR EL CONTENIDO, POR SI YA EXISTE, ANTES DE CREAR EL NODO
	new_node = env_new(new_env);
	if (!new_node)
	{
		free_env(mini);
		return ;
	}
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

/* int	main(int argc, char **argv, char **env)
{
	t_mini	mini;

	(void)argv;
	if (argc != 1)
		return (1);
	printf("///////////////////\n       STETEA EL ENV\n///////////////////\n");
	ft_set_env(env, &mini);
	printf("///////////////////\n       IMPRIME EL ENV\n///////////////////\n");
	ft_print_env(&mini);
	printf("//////////////////\n       BUSCA LA VARIABLE\n//////////////////\n");
	printf("Devuelve: %s\n", ft_get_env("USER", &mini));
	printf("/////////////////\n       EXPORTA LA VARIABLE\n/////////////////\n");
	ft_export_env("INES=ines", &mini);
	printf("///////////////////\n       IMPRIME EL ENV\n///////////////////\n");
	ft_print_env(&mini);
	printf("////////////////\nCAMBIA CONTENIDO DE VARIABLE\n////////////////\n");
	ft_export_env("INES=iines", &mini);
	printf("///////////////////\n       IMPRIME EL ENV\n///////////////////\n");
	ft_print_env(&mini);
	printf("/////////////////\n    DESSTETEA LA VARIABLE\n/////////////////\n");
	ft_unset_env("INES", &mini);
	printf("///////////////////\n       IMPRIME EL ENV\n///////////////////\n");
	ft_print_env(&mini);
}
$ echo $VAR
$var=
$ echo $VAR
$
*/