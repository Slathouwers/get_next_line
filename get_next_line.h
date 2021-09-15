/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:36:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/15 11:32:04 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*
       TEST MALLOC FAIL

# include <stdio.h>
static int fail_after = 19;
static int num_allocs = 1;

static void *xmalloc(size_t size)
{
    if (fail_after > 0 && num_allocs++ >= fail_after)
    {
        printf("Out of memory\n");
        return 0;
    }
    return malloc(size);
}
# define malloc(x)  xmalloc(x) */

//# define MAX_FD		1024
//# define BUFF_SIZE	42

char	*get_next_line(int fd);

char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif