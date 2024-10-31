/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:25:44 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/23 20:39:50 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

volatile sig_atomic_t	g_signal_received = 0;

int	main(int argc, char **argv, char **env)
{
	t_args	args;
	t_mini	mini;
	int		is_piped;

	initialize_structs(&args, &mini, env);
	error_mini_use(argc, argv);
	is_piped = !isatty(STDIN_FILENO);
	if (create_prompt(&mini) == ERR)
		return (ERR);
	signal(SIGINT, signal_sigint);
	signal(SIGQUIT, SIG_IGN);
	create_minim_env_vars(&mini);
	while (1)
	{
		if (initialize_main_loop(&mini, &args, is_piped) == ERR)
			break ;
		histcontrol(&args);
		trim_input(&args);
		if (args.input != NULL && args.input[0] != '\0')
			parse(&args, &mini);
		signal(SIGINT, signal_sigint);
		free(args.input);
		del_params(&args);
	}
	return (closing_minishell(is_piped, &args));
}
