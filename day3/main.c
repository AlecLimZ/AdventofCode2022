/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/02 13:30:42 by leng-chu         ###   ########.fr       */
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
	// must
	FILE	*fptr;
	char	*string;
	size_t	size = 42;
	int		ret;

	// custom

	// must
	string = (char *)malloc(sizeof(char) * 43);
	if (!string)
		exit(1);
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("Error open file\n");
		exit(1);
	}
	// must + custom
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
		printf("%s", string);
	}

	// must
	fclose(fptr);
	free(string);
	return (0);
}
