/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:29:43 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/12 14:23:34 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_built_pwd(char **args)
{
	char	*cwd;
	int		argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc > 1)
		return ;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd");
		return ;
	}
	printf("%s\n", cwd);
	free(cwd);
}
