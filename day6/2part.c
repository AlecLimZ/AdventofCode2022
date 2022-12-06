/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2part.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/06 13:30:17 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int is_mark(char *f)
{
	int i = -1;
	int j;
	int len = strlen(f);
	while (++i < (len - 1) && f[i])
	{
		j = i + 1;
		while (f[j])
		{
			if (f[i] == f[j])
				return (0);
			j++;
		}
	}
	return (1);
}

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
	string = (char *)malloc(sizeof(char) * INT_MAX / 2);
	if (!string)
		exit(1);
	if ((fptr = fopen(av[1], "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
	// x = lose, y = draw, z = win
	char *fw;
	int pos = 0;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
//		printf("STRING: %s", string);
		int i = -1;
		int len = strlen(string) - 14; // because of newline
		while (string[++i] && i < len)
		{
			fw = strndup(string + i, 14);
			if (is_mark(fw))
			{
				printf("%d\n", i + 14);
				break ;
			}
		}
	}

	free(fw);
	// must
	fclose(fptr);
	free(string);
	return (0);
}
