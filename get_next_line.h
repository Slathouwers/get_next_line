/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:36:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/08 19:44:25 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	100


# include <stdlib.h>
# include <unistd.h>

//# define MAX_FD		1024

char	*get_next_line(int fd);
void	ft_cpy(char *dst, const	char *src, size_t m);


#endif