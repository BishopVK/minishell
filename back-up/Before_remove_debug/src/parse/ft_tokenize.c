/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:49:02 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/21 08:28:19 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	control_quotes(char *input_ptr, t_args *args, int *flag)
{
	if (*input_ptr == '\'' && !args->in_double_quote)
	{
		args->in_single_quote = !args->in_single_quote;
		(*flag)++;
		if (*flag % 2 != 0)
			args->quotes[args->argc] = !args->quotes[args->argc];
	}
	else if (*input_ptr == '\"' && !args->in_single_quote)
	{
		args->in_double_quote = !args->in_double_quote;
		(*flag)++;
		if (*flag % 2 != 0)
			args->quotes[args->argc] = !args->quotes[args->argc];
	}
}

static int	verify_closed_quotes(t_args *args)
{
	if (args->in_single_quote || args->in_double_quote)
	{
		ft_dprintf(2, "minishell: syntax error: missing closed quotes\n");
		ft_export_env("?=2", args->mini);
		return (ERR);
	}
	return (OK);
}

static int	loop_through_string(t_args *args, int *argc, t_mini *mini)
{
	char	*input_ptr;
	int		flag;

	input_ptr = args->input;
	flag = 0;
	while (*input_ptr)
	{
		control_quotes(input_ptr, args, &flag);
		if ((ft_isspace(*input_ptr) || *input_ptr == '|' || *input_ptr == '<'
				|| *input_ptr == '>')
			&& !args->in_single_quote && !args->in_double_quote)
		{
			if (out_of_quotes(&input_ptr, args, argc, mini) == ERR)
				return (ERR);
		}
		else
			*args->arg_ptr++ = *input_ptr;
		input_ptr++;
	}
	return (OK);
}

int	add_to_args(t_args *args, int *argc, t_mini *mini)
{
	char	*expander_arg;

	args->quotes[args->argc] = t_false;
	if (loop_through_string(args, argc, mini) == ERR)
		return (ERR);
	if (verify_closed_quotes(args) == ERR)
		return (ERR);
	if (args->arg_ptr != args->arg)
	{
		*args->arg_ptr = '\0';
		expander_arg = expander(args, mini);
		if (expander_arg)
		{
			args->args[(*argc)++] = expander_arg;
		}
	}
	return (OK);
}
