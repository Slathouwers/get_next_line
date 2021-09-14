/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:35:46 by slathouw          #+#    #+#             */
/*   Updated: 2021/09/14 07:32:00 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN(string)	"\033[0;32m" string "\033[0m"

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[3];
	char	*nl;
	int		i;

	i = 1;
	fd[0] = open("./gnlTester/files/41_with_nl", O_RDWR);
	fd[1] = open("./gnlTester/files/42_with_nl", O_RDWR);
	fd[2] = open("./gnlTester/files/43_with_nl", O_RDWR);
	nl = get_next_line(fd[0]);
	printf(GREEN("Line 1 of fd-%i read = \n%s"), fd[0], nl);
	free(nl);
	
	nl = get_next_line(fd[1]);
	printf(GREEN("Line 1 of fd-%i read = \n%s"), fd[1], nl);
	free(nl);

	nl = get_next_line(fd[2]);
	printf(GREEN("Line 1 of fd-%i read = \n%s"), fd[2], nl);
	free(nl);
	
	nl = get_next_line(fd[0]);
	printf(GREEN("Line 2 of fd-%i read = \n%s"), fd[0], nl);
	free(nl);
	
	nl = get_next_line(fd[1]);
	printf(GREEN("\nLine 2 of fd-%i read = \n%s"), fd[1], nl);
	free(nl);

	nl = get_next_line(fd[2]);
	printf(GREEN("\nLine 2 of fd-%i read = \n%s"), fd[2], nl);
	free(nl);
	
/* 	nl = get_next_line(fd[0]);
	printf(GREEN("Line 3 of fd-%i read = \n%s"), fd[0], nl);
	free(nl);
	
	nl = get_next_line(fd[1]);
	printf(GREEN("\nLine 3 of fd-%i read = \n%s"), fd[1], nl);
	free(nl);

	nl = get_next_line(fd[2]);
	printf(GREEN("\nLine 3 of fd-%i read = \n%s"), fd[2], nl);
	free(nl); */
/* 	nl = get_next_line(fd);
	while (nl)
	{
		printf(GREEN("Line %i read = \n%s"), i, nl);
		free(nl);
		nl = get_next_line(fd);
		i++;
	}
	if (!nl)
		printf("(NULL)\n"); */
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}
