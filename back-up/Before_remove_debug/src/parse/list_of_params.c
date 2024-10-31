/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:43:18 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/24 14:31:34 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_last_command_env_var(t_args *args)
{
	t_params	*current;
	char		*tmp;

	current = args->params;
	if (args->params != NULL)
	{
		while (current != NULL)
		{
			if (current->type != INFILE && current->type != HERE_DOC
				&& current->type != OUTFILE && current->type != APPEND)
			{
				tmp = ft_strjoin("_=", current->content);
				ft_export_env(tmp, args->mini);
				free (tmp);
			}
			else
			{
				if (current->next != NULL)
					current = current->next;
				else
					return ;
			}
			current = current->next;
		}
	}
}

void	del_params(t_args *args)
{
	t_params	*current;
	t_params	*next;

	current = args->params;
	if (args->params != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			if (current->content != NULL)
				free(current->content);
			free(current);
			current = next;
		}
		args->params = NULL;
	}
}

static t_bool	is_builtin_command(const char *arg)
{
	if (ft_strcmp(arg, "echo") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "cd") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "pwd") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "export") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "unset") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "env") == 0)
		return (t_true);
	else if (ft_strcmp(arg, "exit") == 0)
		return (t_true);
	return (t_false);
}

static t_param_type	classify_argument(t_args *args, int *argc,
	t_bool *heredoc_found)
{
	if (*heredoc_found == t_true)
		return (*heredoc_found = t_false, DELIMITER);
	if (ft_strcmp(args->args[*argc], "|") == 0
		&& args->quotes[*argc] == t_false)
		return (PIPE);
	else if (ft_strcmp(args->args[*argc], "<") == 0
		&& args->quotes[*argc] == t_false)
		return (INFILE);
	else if (ft_strcmp(args->args[*argc], "<<") == 0
		&& args->quotes[*argc] == t_false)
		return (*heredoc_found = t_true, HERE_DOC);
	else if (ft_strcmp(args->args[*argc], ">") == 0
		&& args->quotes[*argc] == t_false)
		return (OUTFILE);
	else if (ft_strcmp(args->args[*argc], ">>") == 0
		&& args->quotes[*argc] == t_false)
		return (APPEND);
	else if (is_builtin_command(args->args[*argc])
		&& args->quotes[*argc] == t_false)
		return (BUILTING);
	else if (access(args->args[*argc], X_OK) == 0)
		return (CMD);
	else
		return (PARAMS);
}

t_params	*add_argument_to_list(t_args *args, int *argc,
	t_bool *heredoc_found)
{
	t_params	*new_node;
	t_params	*temp;

	if (ft_strlen(args->args[*argc]) == 0 && args->quotes[*argc] == t_false)
		return (NULL);
	new_node = malloc(sizeof(t_params));
	if (!new_node)
		return (NULL);
	new_node->content = ft_strdup(args->args[*argc]);
	new_node->argc = *argc;
	new_node->type = classify_argument(args, argc, heredoc_found);
	new_node->quotes = args->quotes[*argc];
	new_node->next = NULL;
	if (args->params == NULL)
		args->params = new_node;
	else
	{
		temp = args->params;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
