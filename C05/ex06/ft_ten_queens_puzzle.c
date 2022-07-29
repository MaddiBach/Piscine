#include <unistd.h>
#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

#define safesub(x, sub)  (sub > x) ? 0 : (x - sub)  // ici, les parentheses sont utiles pour des raisons de priorite de calcul.
													// une soustraction a une priorite faible, donc en cas de multiplication souhaitee du resultat, la mult se ferait en priorite.x
#define safeadd(x, add)  (x + add > 10) ? 10 : (x + add)

#define min(x, y) (x < y) ? x : y

typedef struct s_pos t_pos;
struct  s_pos
{
	int	x;
	int y;
};

void	set_pos(t_pos *pos, int x, int y)
{
	pos->y = y;
	pos->x = x;
}

t_pos	right_lower_cell(t_pos pos)
{
	if (pos.x > pos.y)
	{
		pos.y = 10 - pos.x;
		pos.x = 10;
	}
	else
	{
		pos.x = 10 - pos.y;
		pos.y = 10;
	}
	return (pos);
}

t_pos	top_right_cell(t_pos pos)
{
	int	x = safesub(pos.x, pos.y);
	int y = safesub(pos.y, pos.x);
	pos.x = pos.x - x;
	pos.y = pos.y - y;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_init_board(char	board[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			 board[i][j] = 'O';
			j++;
		}
		i++;
	}
}


void	ft_print_board(char	board[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			ft_putchar(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_place_queen(char	board[10][10], t_pos pos)
{
	board[pos.y][pos.x] = 'Q';

	t_pos	filler;
	t_pos	limit; // limit position for tracing diagonals
	int		b;

	set_pos(&filler, 0, pos.y);
	while(filler.x < 10)
	{
		if (filler.x == pos.x)
			filler.x++;
		board[filler.y][filler.x] = 'X';
		filler.x++;
	}
	set_pos(&filler, pos.x, 0);
	while(filler.y < 10)
	{
		if (filler.y == pos.y)
			filler.y++;
		board[filler.y][filler.x] = 'X';
		filler.y++;
	}
	set_pos(&filler, safesub(pos.x, pos.y),safesub(pos.y, pos.x));
	limit = right_lower_cell(pos);
	while (filler.x < WIDTH || filler.y < HEIGHT)
	{
		if (filler.y == pos.y && filler.x == pos.x)
		{
			filler.x++;
			filler.y++;
		}
		board[filler.y][filler.x] = 'X';
		filler.x++;
		filler.y++;
	}
	set_pos(&filler, pos.x + pos.y, 0);
	while(filler.x > 0 || filler.y < HEIGHT)
	{
		printf("hey \n");
		if (filler.y == pos.y && filler.x == pos.x)
		{
			filler.y++;
			filler.x--;
		}
		board[filler.y][filler.x] = 'X';
		filler.y++;
		filler.x--;
	}

}

int	ft_ten_queens_puzzle()
{
	char board[10][10] = {0};
	t_pos pos;
	pos.x = 2;
	pos.y = 2;

	ft_init_board(board);
	ft_print_board(board);
	printf("\n----------\n");
	ft_place_queen(board, pos);
	ft_print_board(board);
	return (0);
}

//PSEUDO CODE

//int	ft_ten_queens_puzzle()
//{
//	char board[10][10];
//
// 	while (pos.x < 10)
//	{
//		if (!ft_place_next_queen())   // place next queen retourne false si impossible de placer prochaine reine
//		{
//			pos.x--;
//			ft_ten_queens_puzzle();
//		}
//		x++;
//		if (x ==  10)
//			res++;
//	}
//
//	return (0);
//}


int	main(int ac, char **av)
{
	//int x = atoi(av[1]);
	//int y = atoi(av[2]);
	ft_ten_queens_puzzle();
	//printf("\n %d \n",min(x, y));
	return (0);
}