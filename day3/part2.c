/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/03 13:59:44 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define BUF 42
# define PPL 264

char	ft_findctriple(char *s1, char *s2, char *s3)
{
	int i = -1;
	int j;
	int k;
	while (s1[++i] && s1[i] != '\n')
	{
		j = -1;
		while (s2[++j] && s2[j] != '\n')
		{
			k = -1;
			while (s3[++k] && s3[k] != '\n')
			{
//				printf("%c %c %c\n", s1[i], s2[j], s3[k]);
				if (s1[i] == s2[j] && s1[i] == s3[k])
					return (s1[i]);
			}
		}
	}
	return (0);
}

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
	char	*string1;
	size_t	size = 42;
	int		ret;

	// custom
	int mysize = 53;
	char paZ[53] = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// must
	if (ac != 2)
		return (0);
	string1 = (char *)malloc(sizeof(char) * 43);
	if (!string1)
		exit(1);
	if ((fptr = fopen(av[1], "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
//	int c = 1;
	int	len;
	int sum = 0;
	char *string2;
	char *string3;
	string2 = (char *)malloc(sizeof(char) * 43);
	string3 = (char *)malloc(sizeof(char) * 43);
	while ((ret = getline(&string1, &size, fptr)) != -1)
	{
		// -1 because of newline
		getline(&string2, &size, fptr);
		getline(&string3, &size, fptr);
		char c = ft_findctriple(string1, string2, string3);
		printf("c: %c\n", c);
		for (int i = 0; i < mysize; ++i)
			if (paZ[i] == c)
				sum += i;
	}
	printf("sum: %d\n", sum);

	// must
	fclose(fptr);
	free(string1);
	free(string2);
	free(string3);
	return (0);
}
