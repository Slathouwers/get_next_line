/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:17:58 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/15 10:53:57 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
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
	if (s)
		while (*s++)
			len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *) malloc(len + 1);
	if (!dup)
		return (NULL);
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (dup - len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	char	*start;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	join = (char *) malloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	start = join;
	while (len1--)
		*join++ = *s1++;
	while (len2--)
		*join++ = *s2++;
	*join = '\0';
	return (start);
}
