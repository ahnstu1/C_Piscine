/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok_udlr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:53:30 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 21:49:50 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
	int	n;
}	t_point;

int	space_check(int remain_space, int have_to_be_num)
{
	if (have_to_be_num == 1 && remain_space != 1)
		return (0);
	if (remain_space >= have_to_be_num)
		return (1);
	return (0);
}

int	is_left_ok(t_point p, int num, int (*map)[9], int (*udlr)[9])
{
	int	j;

	j = p.y;
	while (--j >= 0)
		if (map[p.x][j] > num)
			return (1);
	if (space_check(p.y + 1, udlr[2][p.x]))
		return (1);
	return (0);
}

int	is_right_ok(t_point p, int num, int (*map)[9], int (*udlr)[9])
{
	int	j;

	j = p.y;
	while (++j < p.n)
		if (map[p.x][j] > num)
			return (1);
	if (space_check(p.n - p.y, udlr[3][p.x]))
		return (1);
	return (0);
}

int	is_up_ok(t_point p, int num, int (*map)[9], int (*udlr)[9])
{
	int	i;

	i = p.x;
	while (--i >= 0)
		if (map[i][p.y] > num)
			return (1);
	if (space_check(p.x + 1, udlr[0][p.y]))
		return (1);
	return (0);
}

int	is_down_ok(t_point p, int num, int (*map)[9], int (*udlr)[9])
{
	int	i;

	i = p.x;
	while (++i < p.n)
		if (map[i][p.y] > num)
			return (1);
	if (space_check(p.n - p.x, udlr[1][p.y]))
		return (1);
	return (0);
}
