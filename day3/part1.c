/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/05 22:54:33 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define BUF 42
# define PPL 264

char	ft_findc(char *s1, char *s2)
{
	int	i = -1;
	int j;
	while (s1[++i] != '\0')
	{
		j = -1;
		while (s2[++j])
		{
			if (s1[i] == s2[j])
				return (s1[i]);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	// must
	FILE	*fptr;
	char	*string;
	size_t	size = 42;
	int		ret;

	// custom
	int mysize = 53;
	char paZ[53] = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// must
	if (ac != 2)
		return (0);
	string = (char *)malloc(sizeof(char) * 43);
	if (!string)
		exit(1);
	if ((fptr = fopen(av[1], "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
//	int c = 1;
	char	*str1;
	char	*str2;
	int	len;
	int half;
	int sum = 0;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
		// -1 because of newline
		len = strlen(string) - 1;
		half = len / 2;

		str1 = (char *)malloc(sizeof(char) * (half + 1));
		str2 = (char *)malloc(sizeof(char) * (half + 1));
		
		strncpy(str1, string, half);
		str1[half] = '\0';

		strncpy(str2, string + half, half);
		str2[half] = '\0';

		char c = ft_findc(str1, str2);
		printf("c: %c\n", c);
		for (int i = 0; i < mysize; ++i)
			if (paZ[i] == c)
				sum += i;
		free(str1);
		free(str2);
	}
	printf("sum: %d\n", sum);

	// must
	fclose(fptr);
	free(string);
	return (0);
}
