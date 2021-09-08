/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:33:08 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/08 19:42:04 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TODO: DELETE!

////////	UTILS	////////////////
char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return (s);
}
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;

	if(!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *) malloc(len);
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (dup - len);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *join;
	char *start;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *) malloc(len1 + len2 + 1);
	if(!join)
		return (NULL);
	start = join;
	while (len1--)
		*join++ = *s1++;
	while (len2--)
		*join++ = *s2++;
	*join = '\0'; 
	return (start);
}

///////////////////////////////////

void	ft_set_save(char **save, char *text)
{
	if(*save)
	{
		free(*save);
	}
	*save = ft_strdup(text);
	if(text)
	{
		free(text);
		text = NULL;
	}
}

/*
should read BUFF_SIZE bytes from fd and save to save[]
*/
int	save_read_fd(char **save, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes_read;
	char 	*swap;

	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read)
	{
		buff[bytes_read] = '\0';
		swap = ft_strjoin(*save, buff);
		ft_set_save(save, swap);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char			testbuff;
	static char		*save;
	int				bytes_saved;
	char			*nlptr;
	char			*line;

	if (fd < 0 || (read(fd, &testbuff, 0) < 0 && !ft_strlen(save)))
		return (NULL);
	if(!save)
		save = ft_strdup("");
	nlptr = ft_strchr(save, '\n');
	while(!nlptr)
	{
		bytes_saved = save_read_fd(&save, fd);
		if (!bytes_saved)
			break ;
		nlptr = ft_strchr(save, '\n');
	}
	if (ft_strlen(save))
	{
		if (!nlptr)
		{
			line = ft_strdup(save);
			ft_set_save(&save, "");
			return (line);
		}
		*nlptr = '\0';
		line = ft_strdup(save);
		nlptr =	ft_strdup(nlptr + 1);
		ft_set_save(&save, nlptr);
	}
	return (line);
}
