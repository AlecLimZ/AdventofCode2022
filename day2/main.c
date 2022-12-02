/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/02 13:27:17 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define BUF 42
# define PPL 264

// A = rock : 1, B = paper : 2, C = scissors : 3
// X = rock:1, Y = paper:2, Z = sciessors:3

// X = lose, Y = draw, Z = win

int main(int ac, char **av)
{
	// must
	FILE	*fptr;
	char	*string;
	size_t	size = 42;
	int		ret;

	// custom
	int		total = 0;
	int		r = 1;
	int		p = 2;
	int		s = 3;
	int		lose = 0;
	int		draw = 3;
	int		win = 6;

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
	// x = lose, y = draw, z = win
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
		printf("%s", string);
		if (string[0] == 'A' && string[2] == 'X')
			total += (s + lose);
		else if (string[0] == 'A' && string[2] == 'Y')
			total += (r + draw);
		else if (string[0] == 'A' && string[2] == 'Z')
			total += (p + win);
		else if (string[0] == 'B' && string[2] == 'X')
			total += (r + lose);
		else if (string[0] == 'B' && string[2] == 'Y')
			total += (p + draw);
		else if (string[0] == 'B' && string[2] == 'Z')
			total += (s + win);
		else if (string[0] == 'C' && string[2] == 'X')
			total += (p + lose);
		else if (string[0] == 'C' && string[2] == 'Y')
			total += (s + draw);
		else if (string[0] == 'C' && string[2] == 'Z')
			total += (r + win);
	}

	printf("my total score is: %d\n", total);
	// must
	fclose(fptr);
	free(string);
	return (0);
}
