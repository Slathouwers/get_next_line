/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:33:08 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/12 12:35:05 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_set_save(char **save, char *text)
{
	if (*save)
	{
		free(*save);
	}
	*save = ft_strdup(text);
	if (text)
	{
		free(text);
		text = NULL;
	}
}

int	save_read_fd(char **save, int fd)
{
	char	buff[10000000 + 1];
	int		bytes_read;
	char	*swap;

	bytes_read = read(fd, buff, 10000000);
	if (bytes_read)
	{
		buff[bytes_read] = '\0';
		swap = ft_strjoin(*save, buff);
		ft_set_save(save, swap);
	}
	return (bytes_read);
}

char	*get_line(char **save, char *nlptr)
{
	char	*tmp;
	char	*line;

	if (!nlptr)
	{
		line = ft_strdup(*save);
		ft_set_save(save, ft_strdup(""));
		return (line);
	}
	*nlptr = '\0';
	tmp = ft_strdup(*save);
	line = ft_strjoin(tmp, "\n");
	if (tmp)
		free(tmp);
	nlptr = ft_strdup(nlptr + 1);
	ft_set_save(save, nlptr);
	return (line);
}

char	*get_next_line(int fd)
{
	char			testbuff;
	static char		*save;
	int				bytes_saved;
	char			*nlptr;

	if (fd < 0 || (read(fd, &testbuff, 0) < 0 && !ft_strlen(save)))
		return (NULL);
	if (!save)
		save = ft_strdup("");
	nlptr = ft_strchr(save, '\n');
	while (!nlptr)
	{
		bytes_saved = save_read_fd(&save, fd);
		if (!bytes_saved)
			break ;
		nlptr = ft_strchr(save, '\n');
	}
	if (ft_strlen(save))
		return (get_line(&save, nlptr));
	return (NULL);
}
