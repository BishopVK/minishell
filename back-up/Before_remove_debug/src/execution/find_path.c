/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:28:17 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 14:25:45 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_command(char **path_list, char *path_mid, char *kid)
{
	int		j;
	int		i;
	char	*path_fin;

	j = -1;
	while (path_list[++j])
	{
		path_mid = ft_strjoin(path_list[j], "/");
		path_fin = ft_strjoin(path_mid, kid);
		free(path_mid);
		if (access(path_fin, X_OK) == 0)
		{
			i = 0;
			while (path_list[i])
			{
				free(path_list[i]);
				i++;
			}
			free(path_list);
			return (path_fin);
		}
		free(path_fin);
	}
	return (NULL);
}

char	*path_included(char	**kid)
{
	if (access(kid[0], X_OK) == 0)
		return (ft_strdup(kid[0]));
	return (0);
}

char	*get_path_command(char **kid, char **env, char *path_mid)
{
	int		i;
	char	*path;
	char	**path_list;

	if (kid[0] != NULL && ft_strchr(kid[0], '/'))
		return (path_included(kid));
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
		{
			path_list = ft_split(env[i], ':');
			path = check_command(path_list, path_mid, kid[0]);
			if (path)
				return (path);
		}
	}
	i = 0;
	if (path_list)
	{
		while (path_list[i])
			free(path_list[i++]);
		free(path_list);
	}
	return (NULL);
}
