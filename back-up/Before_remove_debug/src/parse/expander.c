/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:07:57 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/22 14:03:36 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*initialize_vars(t_args *args, t_bool *in_double_quotes,
	size_t *i, size_t *j)
{
	args->result_capacity = ft_strlen(args->arg) + 1;
	args->result = malloc(args->result_capacity);
	if (!args->result)
		return (NULL);
	*in_double_quotes = t_false;
	*i = 0;
	*j = 0;
	return (args->result);
}

static char	*realloc_plain_text(t_args *args, size_t *i, size_t *j)
{
	char	*new_result;

	if (*j >= args->result_capacity - 1 && args->result && args->result[*j])
	{
		args->result_capacity += *i;
		new_result = malloc(args->result_capacity);
		if (!new_result)
		{
			free(args->result);
			args->result = NULL;
			return (NULL);
		}
		ft_memcpy(new_result, args->result, *j);
		free(args->result);
		args->result = new_result;
	}
	return (args->result);
}

static void	check_quotes(t_args *args, size_t *i, t_bool *in_double_quotes)
{
	if (args->arg[*i] == '\'' && !*in_double_quotes)
		args->in_single_quote = !args->in_single_quote;
	if (args->arg[*i] == '"' && !args->in_single_quote)
		*in_double_quotes = !*in_double_quotes;
	(*i)++;
}

static int	dollar_quotes_case(t_args *args, t_bool *in_double_quotes,
	size_t *i, size_t *j)
{
	if (args->arg[*i + 1] == '"' || args->arg[*i + 1] == '\'')
	{
		if (*in_double_quotes)
			args->result[(*j)++] = '$';
		(*i)++;
	}
	else if (!expand_vars(args, i, j, args->mini))
		return (ERR);
	return (OK);
}

char	*expander(t_args *args, t_mini *mini)
{
	size_t	i;
	size_t	j;
	t_bool	in_double_quotes;

	if (!initialize_vars(args, &in_double_quotes, &i, &j))
		return (NULL);
	while (args->arg[i])
	{
		if (!realloc_plain_text(args, &i, &j))
			return (NULL);
		if ((args->arg[i] == '\'' && !in_double_quotes)
			|| (args->arg[i] == '"' && !args->in_single_quote))
			check_quotes(args, &i, &in_double_quotes);
		else if (args->arg[i] == '$' && !args->in_single_quote
			&& !args->in_heredoc)
		{
			if (dollar_quotes_case(args, &in_double_quotes, &i, &j) == ERR)
				return (NULL);
		}
		else
			copy_chars_unless_its_quote(args, &i, &j);
	}
	args->result[j] = '\0';
	(void)mini;
	return (args->result);
}
