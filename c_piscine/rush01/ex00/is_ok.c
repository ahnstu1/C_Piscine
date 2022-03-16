/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:47:05 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 21:49:48 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
	int	n;
}	t_point;

int	is_left_ok(t_point p, int num, int (*map)[9], int (*udlr)[9]);
int	is_right_ok(t_point p, int num, int (*map)[9], int (*udlr)[9]);
int	is_up_ok(t_point p, int num, int (*map)[9], int (*udlr)[9]);
int	is_down_ok(t_point p, int num, int (*map)[9], int (*udlr)[9]);

int	is_there_same(t_point p, int num, int (*map)[9])
{
	int	i;

	i = 0;
	while (i < p.n)
	{
		if (map[p.x][i] == num)
			return (1);
		if (map[i][p.y] == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_ok(t_point p, int num, int (*map)[9], int (*udlr)[9])
{
	if (map[p.x][p.y] != 0)
		return (0);
	if (is_there_same(p, num, map))
		return (0);
	if (!is_left_ok(p, num, map, udlr))
		return (0);
	if (!is_right_ok(p, num, map, udlr))
		return (0);
	if (!is_up_ok(p, num, map, udlr))
		return (0);
	if (!is_down_ok(p, num, map, udlr))
		return (0);
	return (1);
}
