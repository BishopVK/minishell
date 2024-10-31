/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:15:19 by danjimen &        #+#    #+#             */
/*   Updated: 2024/09/24 11:23:30 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*errno_case(t_args *args, size_t *i, size_t *j, t_mini *mini)
{
	int		env_len;
	char	*new_result;

	if (ft_find_env(mini, "?"))
	{
		env_len = ft_strlen(ft_find_env(mini, "?"));
		if (*j + env_len >= args->result_capacity - 1)
		{
			args->result_capacity += env_len - 2;
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
		ft_strcpy(args->result + *j, ft_find_env(mini, "?"));
		*j += env_len;
	}
	*i += 2;
	return (args->result);
}

static char	*valid_var(t_args *args, size_t *i, size_t *j, int *start)
{
	char	*env_value;
	char	*sub_str_or_new_result;

	sub_str_or_new_result = ft_substr(args->arg, *start, *i - *start);
	env_value = ft_find_env(args->mini, sub_str_or_new_result);
	free(sub_str_or_new_result);
	if (env_value)
	{
		if (*j + ft_strlen(env_value) >= args->result_capacity - 1)
		{
			args->result_capacity += ft_strlen(env_value) - 1;
			sub_str_or_new_result = malloc(args->result_capacity);
			if (!sub_str_or_new_result)
			{
				free(args->result);
				return (args->result = NULL, NULL);
			}
			ft_memcpy(sub_str_or_new_result, args->result, *j);
			free(args->result);
			args->result = sub_str_or_new_result;
		}
		ft_strcpy(args->result + *j, env_value);
		*j += ft_strlen(env_value);
	}
	return (args->result);
}

static char	*next_is_number_or_valid(t_args *args, size_t *i, size_t *j)
{
	char	next_char;
	int		start;

	next_char = args->arg[*i];
	if (ft_isdigit(next_char) || next_char == '*')
		(*i)++;
	else if (!ft_isalpha(next_char) && next_char != '_')
	{
		args->result[(*j)++] = '$';
		args->result[(*j)++] = next_char;
		(*i)++;
	}
	else
	{
		start = *i;
		while (args->arg[*i] && (ft_isalnum(args->arg[*i])
				|| args->arg[*i] == '_'))
			(*i)++;
		if (!valid_var(args, i, j, &start))
			return (NULL);
	}
	return (args->result);
}

char	*expand_vars(t_args *args, size_t *i, size_t *j, t_mini *mini)
{
	if (args->arg[*i + 1] == '?')
	{
		if (!errno_case(args, i, j, mini))
			return (NULL);
	}
	else
	{
		(*i)++;
		if (args->arg[*i] == '\0'
			|| (args->arg[*i] == '"' && args->arg[*i + 1] == '\0'))
			args->result[(*j)++] = '$';
		else
		{
			if (!next_is_number_or_valid(args, i, j))
				return (NULL);
		}
	}
	return (args->result);
}

void	copy_chars_unless_its_quote(t_args *args, size_t *i, size_t *j)
{
	args->result[(*j)++] = args->arg[(*i)++];
	if (args->in_heredoc)
		args->in_heredoc = t_false;
}
