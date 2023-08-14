#include <unistd.h>

#define SIZE 4

int	solve(int board[SIZE][SIZE], int clues[16], int row, int col);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

void	init_args(int *clues, char *argv, int board[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < SIZE * 4)
	{
		clues[i] = argv[i * 2] - 48;
	}
	i = -1;
	while (++i < SIZE)
	{
		while (++j < SIZE)
		{
			board[i][j] = 0;
		}
		j = -1;
	}
}

void	put_board(int board[SIZE][SIZE])
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	j = -1;
	while (++i < SIZE)
	{
		while (++j < SIZE)
		{
			temp = board[i][j] + 48;
			write(1, &temp, 1);
			if (j != 3)
				write(1, " ", 1);
		}
		j = -1;
		write(1, "\n", 1);
	}
}

int	is_error(int argc, char *argv)
{
	int	i;

	if (argc != 2 || ft_strlen(argv) != (SIZE * 8) - 1)
		return (1);
	if (argc != 2)
		return (1);
	i = -1;
	while (argv[++i] != '\0')
	{
		if (i % 2 == 0 && (argv[i] < '1' || argv[i] > SIZE + 48))
			return (1);
		else if (i % 2 == 1 && argv[i] != ' ')
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	clues[SIZE * 4];
	int	board[SIZE][SIZE];

	if (is_error(argc, argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_args(clues, argv[1], board);
	if (solve(board, clues, 0, 0))
		put_board(board);
	else
		write(1, "Error\n", 6);
}
