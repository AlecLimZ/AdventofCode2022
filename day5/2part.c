/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2part.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:07:53 by leng-chu          #+#    #+#             */
/*   Updated: 2022/12/05 22:51:59 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	initstack(char **stack)
{
	int pos = -1;
	while (++pos < 10)
		stack[pos] = (char*)malloc(sizeof(char) * 100);
	stack[pos] = NULL;
	char a[422] = "ZTFRWJG";
	char b[422] = "GWM";
	char c[422] = "JNHG";
	char d[422] = "JRCNW";
	char e[422] = "WFSBGQVM";
	char f[422] = "SRTDVWC";
	char g[422] = "HBNCDZGV";
	char h[422] = "SJNMGC";
	char i[422] = "GPNWCJDL";
	
	stack[0][0] = 'a';
	stack[0][1] = '\0';
	pos = -1;
	while (++pos <= strlen(a))
		stack[1][pos] = a[pos];
	pos = -1;
	while (++pos <= strlen(b))
		stack[2][pos] = b[pos];
	pos = -1;
	while (++pos <= strlen(c))
		stack[3][pos] = c[pos];
	pos = -1;
	while (++pos <= strlen(d))
		stack[4][pos] = d[pos];
	pos = -1;
	while (++pos <= strlen(e))
		stack[5][pos] = e[pos];
	pos = -1;
	while (++pos <= strlen(f))
		stack[6][pos] = f[pos];
	pos = -1;
	while (++pos <= strlen(g))
		stack[7][pos] = g[pos];
	pos = -1;
	while (++pos <= strlen(h))
		stack[8][pos] = h[pos];
	pos = -1;
	while (++pos <= strlen(i))
		stack[9][pos] = i[pos];
}

void	domove(int move, char *from, char *to)
{
	printf("Before - from: %s   to: %s\n", from, to);
	int top = strlen(from); // it is NULL
	char *m = (char *)malloc(sizeof(char) * (move + 1));
	int p = -1;
	int fi = top - move;
	while (++p < move)
	{
		m[p] = from[fi];
		from[fi++] = 0;
	}
	m[p] = '\0';
	strcat(to, m);
	free(m);
	printf("After - from: %s   to: %s\n\n", from, to);
}

int main(int ac, char **av)
{
	// must
	FILE	*fptr;
	char	*string;
	size_t	size = 42;
	int		ret;

	if (ac != 2)
		return (1);
	// custom
	char **stack = (char**)malloc(sizeof(char*) * 11);
	char code[42] = "@abcdefghi";
	initstack(stack);

	// must
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
	int move = 0;
//	char from = 0;
//	char to = 0;
	int from = 0;
	int to = 0;
	int pos = 0;
	while ((ret = getline(&string, &size, fptr)) != -1)
	{
//		printf("%s", string);
		pos = 0;
		while (!isdigit(string[pos]))
			pos++;
		move = atoi(string + pos);
		while (isdigit(string[pos]))
			pos++;
		while (!isdigit(string[pos]))
			pos++;
//		from = code[atoi(string + pos)]; // for char
		from = atoi(string + pos); // for int
		while (isdigit(string[pos]))
			pos++;
		while (!isdigit(string[pos]))
			pos++;
		to = atoi(string + pos);
		//printf("move: %d   from: %c   to: %c\n", move, from, to); // for char
		printf("move: %d   from: %d   to: %d\n", move, from, to); // for int
		domove(move, stack[from], stack[to]);
	}

	for (int i = 0; i < 10; ++i)
		printf("%s\n", stack[i]);
	// must
	fclose(fptr);
	for (int i = 0; stack[i]; ++i)
		free(stack[i]);
	free(stack);
	free(string);
	return (0);
}
