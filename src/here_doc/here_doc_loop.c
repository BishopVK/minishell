/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:25:32 by danjimen          #+#    #+#             */
/*   Updated: 2024/10/23 22:06:56 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*initialize_here_doc(t_params *param, t_args *here_doc, t_mini *mini)
{
	char	*eof;

	eof = param->content;
	ft_bzero(here_doc, sizeof(t_args));
	here_doc->mini = mini;
	signal(SIGINT, signal_here_doc);
	g_signal_received = 0;
	return (eof);
}

static char	*ft_get_eof(char *eof)
{
	char	*eof_fin;

	eof_fin = (char *)malloc(ft_strlen(eof) + 2);
	ft_strlcpy(eof_fin, eof, ft_strlen(eof) + 1);
	eof_fin[ft_strlen(eof)] = '\n';
	eof_fin[ft_strlen(eof) + 1] = '\0';
	return (eof_fin);
}

static int	initialize_here_doc_loop(t_args	*here_doc, char *eof, t_params *param, char **eof_fin)
{
	if (g_signal_received == SIGINT)
		return (ERR);
	here_doc->arg = readline("> ");
	if (!here_doc->arg)
	{
		ft_dprintf(2, "minishell: warning: here-document delimited by"
			" end-of-file (wanted `EOF')\n");
		return (ERR);
	}
	if (g_signal_received == SIGINT)
	{
		free(here_doc->arg);
		return (ERR);
	}
	if (eof[0] == '$' && ft_strlen(eof) >= 1 && param->quotes == t_true)
		*eof_fin = ft_substr(eof, 1, ft_strlen(eof));
	else
		*eof_fin = ft_get_eof(eof);
	return (OK);
}

int	here_doc_loop(int fd, t_params *param, t_mini *mini)
{
	t_args	here_doc;
	char	*eof;
	char	*eof_fin;

	eof = initialize_here_doc(param, &here_doc, mini);
	while (1)
	{
		if (initialize_here_doc_loop(&here_doc, eof, param, &eof_fin) == ERR)
			break ;
		if ((eof[0] == '\0' && here_doc.arg[0] == '\0')
			|| (!ft_strncmp(eof_fin, here_doc.arg, ft_strlen(here_doc.arg))
			&& ft_strlen(here_doc.arg) > 0) || (eof[0] == '$'
			&& ft_strlen(eof) == 1 && param->quotes == t_true
			&& here_doc.arg[0] == '\0'))
		{
			free(here_doc.arg);
			free(eof_fin);
			break ;
		}
		if (param->quotes == t_false)
		{
			expander(&here_doc, mini);
			printf("DB: expanded_arg => %s\n", here_doc.result);
			write(fd, here_doc.result, ft_strlen(here_doc.result));
			write(fd, "\n", 1);
			free(here_doc.arg);
			free(here_doc.result);
			free(eof_fin);
		}
		else
		{
			write(fd, here_doc.arg, ft_strlen(here_doc.arg));
			write(fd, "\n", 1);
			free(here_doc.arg);
			free(eof_fin);
		}
	}
	signal(SIGINT, signal_sigint);
	if (g_signal_received == SIGINT)
	{
		g_signal_received = 0;
		close(fd);
		return (-2);
	}
	return (OK);
}
