/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/07 14:20:38 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int main(int ac, char **av)
{
	// must
	FILE	*fptr;
	char	*string;
	size_t	size = 42;
	int		ret;

	// custom

	// must
	if (ac != 2)
		return (1);
	string = (char *)malloc(sizeof(char) * (INT_MAX / 2));
	if (!string)
		exit(1);
	if ((fptr = fopen(av[1], "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
	int	*box = (int *)malloc(sizeof(int) * (INT_MAX / 2));
	int bpos = 0;
	int sum = 0;

	// up to 100000
	int limit = 100000;
	int get = 0;
	int index;
	// x = lose, y = draw, z = win
	int ls = 0;

	// store dir names
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
		index = 0;
		while (string[index] && !isdigit(string[index]))
			index++;
		if (string[index])
			printf("%d\n", atoi(string + index));
		else
			printf("%s", string);
	}
	// must
	fclose(fptr);
	free(string);
	return (0);
}
