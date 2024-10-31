/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:25:19 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/24 13:15:41 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_here_doc_file_name(void)
{
	int		i;
	char	*file_num;
	char	*file_name;

	i = 0;
	file_num = ft_itoa(i);
	file_name = ft_strjoin(file_num, ".tmp");
	free(file_num);
	while (access(file_name, F_OK) == 0)
	{
		i++;
		free(file_name);
		file_num = ft_itoa(i);
		file_name = ft_strjoin(file_num, ".tmp");
		free(file_num);
	}
	return (file_name);
}

static int	ft_here_doc(t_params *param, t_mini *mini, int fd)
{
	t_list	*temp_here_doc;
	char	*file_name;

	file_name = get_here_doc_file_name();
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		return (free(file_name), ERR);
	temp_here_doc = ft_lstnew(file_name);
	if (temp_here_doc == NULL)
	{
		unlink(file_name);
		ft_lstclear(&mini->here_doc_files, free);
		close(fd);
		return (ERR);
	}
	ft_lstadd_back(&mini->here_doc_files, temp_here_doc);
	if (here_doc_loop(fd, param, mini) == -2)
		return (-2);
	close (fd);
	fd = open(file_name, O_RDONLY, 0777);
	return (fd);
}

int	*get_here_doc(t_params *iter_params, t_args *args, int i)
{
	int	*here_doc_fds;

	here_doc_fds = NULL;
	while (iter_params != NULL)
	{
		if (iter_params->type == HERE_DOC)
			i++;
		iter_params = iter_params->next;
	}
	if (i > 0)
		here_doc_fds = malloc(i * sizeof(int *));
	i = 0;
	iter_params = args->params;
	while (iter_params != NULL)
	{
		if (iter_params->type == HERE_DOC)
		{
			here_doc_fds[i] = ft_here_doc(iter_params->next, args->mini, 0);
			if (here_doc_fds[i] == -2)
				return (here_doc_fds);
			i++;
		}
		iter_params = iter_params->next;
	}
	return (here_doc_fds);
}
