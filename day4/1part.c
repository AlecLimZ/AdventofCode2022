/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1part.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/04 13:48:45 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	string = (char *)malloc(sizeof(char) * 43);
	if (!string)
		exit(1);
	if ((fptr = fopen(av[1], "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
	// x = lose, y = draw, z = win
	int a1;
	int a2;
	int b1;
	int b2;
	int	pair = 0;
	int len1;
	int len2;
	int i;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
//		printf("%s", string);
		i = 0;
		a1 = atoi(string);
		while (string[i] != '-')
			i++;
		i++;
		a2 = atoi(string + i);
		while (string[i] != ',')
			i++;
		i++;
		b1 = atoi(string + i);
		while (string[i] != '-')
			i++;
		i++;
		b2 = atoi(string + i);
		len1 = 0;
		len2 = 0;
		for (int i = a1; i <= a2; ++i)
			len1++;
		for (int i = b1; i <= b2; ++i)
			len2++;
		if (a1 <= b1 && a2 >= b2)
		{
			printf("CONTAIN: %d-%d len1: %d | %d-%d len2: %d\n", a1, a2, len1, b1, b2, len2);
			pair++;
		}
		else if (b1 <= a1 && b2 >= a2)
		{
			printf("CONTAIN: %d-%d len1: %d | %d-%d len2: %d\n", a1, a2, len1, b1, b2, len2);
			pair++;
		}
		else
			printf("CLEAR: %d-%d len1: %d | %d-%d len2: %d\n", a1, a2, len1, b1, b2, len2);
  }
	printf("pair: %d\n", pair);
	// must
	fclose(fptr);
	free(string);
	return (0);
}
