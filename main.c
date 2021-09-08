/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:35:46 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/08 19:44:22 by slathouw         ###   ########.fr       */
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

	fd = open("./test.txt", O_RDONLY);
	nl = get_next_line(fd);
	while (nl)
	{
		printf(GREEN("Line read = \n%s\n"), nl);
		nl = get_next_line(fd);
	}
	if (!nl)
		printf("(NULL)");
	close(fd);
}
