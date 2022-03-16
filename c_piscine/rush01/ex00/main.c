/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:47:17 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 22:31:44 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	n;
}	t_point;

static int	g_map[9][9];
static int	g_n;
static int	g_udlr[4][9];

int		is_ok(t_point p, int num, int (*map)[9], int (*udlr)[9]);
int		arg_to_arr(char *str, int (*udlr)[9]);
void	substract_rc(t_point p, int *rec, int (*map)[9], int (*udlr)[9]);
void	restore_rc(t_point p, int *rec, int (*udlr)[9]);
void	print_map(int (*map)[9], int n);

void	put_num_on_map(t_point p, int num, int *rec)
{
	g_map[p.x][p.y] = num;
	substract_rc(p, rec, g_map, g_udlr);
}

void	remove_num_on_map(t_point p, int *rec)
{
	g_map[p.x][p.y] = 0;
	restore_rc(p, rec, g_udlr);
}

int	fill_number(int row, int num, int check)
{
	int		rec[4];
	int		i;
	t_point	p;

	if (num <= 0)
	{
		print_map(g_map, g_n);
		return (1);
	}
	if (row >= g_n)
		return (fill_number(0, num - 1, 0));
	i = -1;
	while (++i < g_n && check == 0)
	{
		p.x = row;
		p.y = i;
		p.n = g_n;
		if (is_ok(p, num, g_map, g_udlr))
		{
			put_num_on_map(p, num, rec);
			check = fill_number(row + 1, num, 0);
			remove_num_on_map(p, rec);
		}
	}
	return (check);
}

int	main(int argc, char **argv)
{
	int	num_count;
	int	check;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num_count = arg_to_arr(argv[1], g_udlr);
	if (num_count % 4 != 0 || num_count > 36 || num_count == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	g_n = num_count / 4;
	check = fill_number(0, g_n, 0);
	if (check == 0)
		write(1, "Error\n", 6);
	return (0);
}
