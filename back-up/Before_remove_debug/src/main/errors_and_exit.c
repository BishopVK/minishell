/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:16:32 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/23 20:42:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_args_at_exit(t_args *args)
{
	if (args->input)
	{
		free (args->input);
		args->input = NULL;
	}
	if (args->arg)
	{
		free (args->arg);
		args->arg = NULL;
	}
	if (args->mini->user_prompt)
	{
		free (args->mini->user_prompt);
		args->mini->user_prompt = NULL;
	}
	if (args->mini->exe_command)
	{
		exe_struct_free (args->mini);
		args->mini->exe_command = NULL;
	}
	if (args->last_history)
	{
		free(args->last_history);
		args->last_history = NULL;
	}
}

void	free_at_exit(t_args *args)
{
	close(args->mini->standard_fds[0]);
	close(args->mini->standard_fds[1]);
	free_args_at_exit(args);
	free_env(args->mini);
	del_params(args);
	rl_clear_history();
}

void	error_mini_use(int argc, char **argv)
{
	int	i;

	if (argc != 1)
	{
		printf("%s: ", argv[0]);
		i = 1;
		while (i < argc)
		{
			printf("%s", argv[i++]);
			if (i != (argc))
				printf(", ");
		}
		ft_dprintf(2, "minishell: Not flags or args are allowed\n");
		exit (1);
	}
}

void	free_args_in_syntax_error(t_args *args)
{
	int	i;

	i = 0;
	if (args->args[i])
	{
		while (args->args[i])
		{
			printf("DB: Libero %s por syntax error\n", args->args[i]);
			free(args->args[i]);
			args->args[i] = NULL;
			i++;
		}
	}
}

int	closing_minishell(int is_piped, t_args *args)
{
	if (!is_piped)
		printf("exit\n");
	else if (is_piped)
	{
		free_at_exit(args);
		return (127);
	}
	free_at_exit(args);
	return (0);
}
