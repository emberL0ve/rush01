/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghysbre <fghysbre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:03:33 by fghysbre          #+#    #+#             */
/*   Updated: 2023/08/13 15:02:16 by fghysbre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	cvis(int line[SIZE])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < SIZE)
	{
		if (line[i] > max_height)
		{
			count++;
			max_height = line[i];
		}
		i++;
	}
	return (count);
}

void	init_hoz_line(int *l, int *r, int board[SIZE][SIZE], int a)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		l[i] = board[a][i];
		r[i] = board[a][SIZE - 1 - i];
		i++;
	}
}

void	init_ver_line(int *t, int *b, int board[SIZE][SIZE], int a)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		t[i] = board[i][a];
		b[i] = board[SIZE - 1 - i][a];
		i++;
	}
}

int	is_grid_valid(int board[SIZE][SIZE], int clues[16])
{
	int	top_line[SIZE];
	int	bottom_line[SIZE];
	int	left_line[SIZE];
	int	right_line[SIZE];
	int	i;

	i = 0;
	while (i < SIZE)
	{
		init_hoz_line(left_line, right_line, board, i);
		init_ver_line(top_line, bottom_line, board, i);
		if (clues[i] != 0 && cvis(top_line) != clues[i])
			return (0);
		else if (clues[i + 4] != 0 && cvis(bottom_line) != clues[i + 4])
			return (0);
		else if (clues[i + 8] != 0 && cvis(left_line) != clues[i + 8])
			return (0);
		else if (clues[i + 12] != 0 && cvis(right_line) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}
