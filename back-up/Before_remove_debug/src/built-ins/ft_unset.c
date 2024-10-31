/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:24:26 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/03 22:42:58 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_built_unset(char **args, t_mini *mini)
{
	int	i;
	int	argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc == 1)
		return (0);
	i = 1;
	while (args[i])
	{
		ft_unset_env(args[i], mini);
		i++;
	}
	return (0);
}
