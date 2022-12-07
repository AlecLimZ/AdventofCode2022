/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1part.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/07 14:15:36 by leng-chu         ###   ########.fr       */
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
	char **dirbox = (char**)malloc(sizeof(char) * (INT_MAX / 2));
	int dpos = 0;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
//		printf("%s", string);
		index = 0;
		get = 0;
		if (string[0] == 'd')
			dirbox[dpos++] = strdup(string + 4);
		if (!strcmp(string, "$ ls\n"))
			ls = 1;
		if (string[2] == 'c' && string[3] == 'd')
			ls = 0;
		while (string[index] && !isdigit(string[index]))
			index++;
		if (ls == 1 && string[index])
			get = atoi(string + index);
		printf("ls: %d ,get: %d\n", ls, get);
		if (ls == 1)
			sum += get;
		else if (ls == 0)
		{
			if (sum != 0)
				box[bpos++] = sum;
			sum = 0;
		}
	}
	// must
	for (int k = 0; k < bpos; ++k)
		printf("%d\n", box[k]);
	int totaldir = 0;
	for (int k = 0; dirbox[k]; ++k)
	{
		totaldir++;
		printf("%s", dirbox[k]);
	}
	printf("total: %d : %d\n", totaldir, bpos);
	fclose(fptr);
	free(string);
	return (0);
}
