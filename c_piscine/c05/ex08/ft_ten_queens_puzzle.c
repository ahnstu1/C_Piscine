/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:41:01 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 16:31:16 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	field_print(int (*field)[10])
{
	int		row_idx;
	int		col_idx;
	char	output;

	col_idx = -1;
	while (++col_idx < 10)
	{
		row_idx = -1;
		while (++row_idx < 10)
		{
			if (field[col_idx][row_idx])
			{
				output = row_idx + '0';
				write(1, &output, 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
}

int	diagonal_ok(int (*field)[10], int col, int row)
{
	int	row_rec;
	int	col_rec;

	row_rec = row;
	col_rec = col;
	while (row_rec != 0 && col_rec != 0)
	{
		row_rec--;
		col_rec--;
	}
	while (col_rec != 10 && row_rec != 10)
		if (field[col_rec++][row_rec++])
			return (1);
	while (col != 9 && row != 0)
	{
		row--;
		col++;
	}
	while (col != -1 && row != 10)
		if (field[col--][row++])
			return (1);
	return (0);
}

int	is_ok(int (*field)[10], int col, int row)
{
	int	idx;

	idx = -1;
	while (++idx < 10)
	{
		if (idx != col && field[idx][row] == 1)
			return (0);
		if (idx != row && field[col][idx] == 1)
			return (0);
	}
	if (diagonal_ok(field, col, row))
		return (0);
	return (1);
}

void	case_maker(int (*field)[10], int col, int row, int *result)
{
	if (col == 10)
	{
		*result += 1;
		field_print(field);
		return ;
	}	
	while (row < 10)
	{
		if (is_ok(field, col, row))
		{
			field[col][row] = 1;
			case_maker(field, col + 1, 0, result);
			field[col][row] = 0;
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	col;
	int	row;
	int	field[10][10];
	int	result;

	col = 0;
	result = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10)
			field[col][row++] = 0;
		col++;
	}
	case_maker(field, 0, 0, &result);
	return (result);
}
