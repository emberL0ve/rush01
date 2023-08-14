#define SIZE 4

int	is_grid_valid(int board[SIZE][SIZE], int clues[16]);

// Check if height is not in the current row or column
int	is_valid(int board[SIZE][SIZE], int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (board[row][i] == height || board[i][col] == height)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int board[SIZE][SIZE], int clues[16], int row, int col)
{
	int	height;

	height = 1;
	if (row == SIZE)
		return (is_grid_valid(board, clues));
	if (col == SIZE)
		return (solve(board, clues, row + 1, 0));
	while (height <= SIZE)
	{
		if (is_valid(board, row, col, height))
		{
			board[row][col] = height;
			if (solve(board, clues, row, col + 1))
				return (1);
			board[row][col] = 0;
		}
		height++;
	}
	return (0);
}
