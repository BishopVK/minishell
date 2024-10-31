/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:35:25 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/24 11:10:27 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_count_elements(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	split_args(t_params *temp, int i, int n_commands)
{
	char		**arg_splited;
	t_params	*new_node;

	arg_splited = ft_split(temp->content, ' ');
	free(temp->content);
	temp->content = ft_strdup(arg_splited[i]);
	free (arg_splited[i]);
	i++;
	while (i < n_commands)
	{
		new_node = malloc(sizeof(t_params));
		if (!new_node)
			return (-1);
		new_node->content = ft_strdup(arg_splited[i]);
		free (arg_splited[i]);
		new_node->type = PARAMS;
		new_node->quotes = t_false;
		new_node->next = temp->next;
		temp->next = new_node;
		temp = temp->next;
		i++;
	}
	free (arg_splited);
	return (0);
}

static int	reorder_argc(t_params *params, t_params *temp)
{
	int	args_len;
	int	i;

	temp = params;
	i = 0;
	args_len = 0;
	while (temp != NULL)
	{
		if (temp->content[0] == '|' && temp->next
			&& temp->next->content[0] == '|')
		{
			ft_dprintf(2, "bash: syntax error near unexpected token `|'\n");
			return (ERR);
		}
		args_len += ft_strlen(temp->content);
		temp->argc = i;
		i++;
		temp = temp->next;
	}
	return (args_len);
}

static int	check_pipes(t_params *params, t_params *temp)
{
	int	nbr_nodes;
	int	i;

	temp = params;
	nbr_nodes = 0;
	while (temp != NULL)
	{
		nbr_nodes++;
		temp = temp->next;
	}
	i = 1;
	temp = params;
	while (temp != NULL)
	{
		if ((i == 1 || i == nbr_nodes) && temp->content[0] == '|')
		{
			ft_dprintf(2, "bash: syntax error near unexpected token `|'\n");
			return (ERR);
		}
		i++;
		temp = temp->next;
	}
	return (OK);
}

int	ft_retokenize(t_params *params)
{
	t_params	*temp;
	int			n_commands;
	int			i;
	int			args_len;

	temp = params;
	while (temp != NULL)
	{
		n_commands = 1;
		if ((temp->type == BUILTING || temp->type == CMD
				|| temp->type == PARAMS) && temp->quotes == t_false)
			n_commands = ft_count_elements(temp->content, ' ');
		i = 0;
		if (n_commands > 1)
			if (split_args(temp, i, n_commands) == -1)
				return (-1);
		temp = temp->next;
	}
	args_len = reorder_argc(params, temp);
	if (args_len != ERR && check_pipes(params, temp) == ERR)
		args_len = ERR;
	return (args_len);
}
