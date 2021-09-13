/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:35:46 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/13 13:50:08 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN(string)	"\033[0;32m" string "\033[0m"

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*nl;
	int		i;

	i = 1;
	fd = open("./test.txt", O_RDONLY);
	nl = get_next_line(fd);
	while (nl)
	{
		printf(GREEN("Line %i read = \n%s"), i, nl);
		free(nl);
		nl = get_next_line(fd);
		i++;
	}
	if (!nl)
		printf("(NULL)\n");
	close(fd);
}
