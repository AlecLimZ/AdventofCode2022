/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/01 16:00:12 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define BUF 42
# define PPL 264
int main(int ac, char **av)
{
	FILE	*fptr;
	int		num;
	char	*string;
	size_t	size = 42;
	int		ret;
	int 	list[265];

	string = (char *)malloc(sizeof(char) * 43);
	if (!string)
		exit(1);
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	int i = 0;
	int sum = 0;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
		if (strcmp(string, "") == 10)
		{
			list[i++] = sum;
			sum = 0;
		}
		else
		{
			sum += atoi(string);
		}
	}
	list[i] = sum;
	int max = list[0];
	int max2 = 0;
	int max3 = 0;
	for (int i = 0; i < 264; i++)
		max = max > list[i] ? max : list[i];
	for (int i = 0; i < 264; i++)
		if (list[i] != max)
			max2 = max2 > list[i] ? max2 : list[i];
	for (int i = 0; i < 264; i++)
		if (list[i] != max && list[i] != max2)
			max3 = max3 > list[i] ? max3 : list[i];
	printf("1: %d\n", max);
	printf("2: %d\n", max2);
	printf("3: %d\n", max3);
	printf("total: %d\n", max + max2 + max3);
	fclose(fptr);
	free(string);
	return (0);
}
