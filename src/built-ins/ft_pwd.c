/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:29:43 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/20 14:36:15 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_built_pwd(char **args, t_mini *mini)
{
	char	*cwd;
	int		argc;

	argc = 0;
	while (args[argc])
		argc++;
	/* if (argc > 1)
		return (ft_dprintf(2, "minishell: pwd: Args not allowed\n"), 1); */
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		if (ft_find_env(mini, "PWD"))
		{
			cwd = ft_strdup(ft_find_env(mini, "PWD"));
			printf("%s\n", cwd);
			free (cwd);
			return (0);
		}
		perror("minishell: getcwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
