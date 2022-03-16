/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:03:30 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 21:49:45 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
	int	n;
}	t_point;

int	is_sub_up(t_point p, int (*map)[9])
{
	int	i;

	i = p.x - 1;
	while (i >= 0)
	{
		if (map[i][p.y] > map[p.x][p.y])
			return (0);
		i--;
	}
	return (1);
}

int	is_sub_right(t_point p, int (*map)[9])
{
	int	j;

	j = p.y + 1;
	while (j < p.n)
	{
		if (map[p.x][j] > map[p.x][p.y])
			return (0);
		j++;
	}
	return (1);
}

int	is_sub_down(t_point p, int (*map)[9])
{
	int	i;

	i = p.x + 1;
	while (i < p.n)
	{
		if (map[i][p.y] > map[p.x][p.y])
			return (0);
		i++;
	}
	return (1);
}

int	is_sub_left(t_point p, int (*map)[9])
{
	int	j;

	j = p.y - 1;
	while (j >= 0)
	{
		if (map[p.x][j] > map[p.x][p.y])
			return (0);
		j--;
	}
	return (1);
}
