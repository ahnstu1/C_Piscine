/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:53 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 21:49:51 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_point
{
	int	x;
	int	y;
	int	n;
}	t_point;

int	is_sub_up(t_point p, int (*map)[9]);
int	is_sub_right(t_point p, int (*map)[9]);
int	is_sub_down(t_point p, int (*map)[9]);
int	is_sub_left(t_point p, int (*map)[9]);

void	restore_rc(t_point p, int *rec, int (*udlr)[9])
{
	if (rec[0])
		udlr[0][p.y]++;
	if (rec[1])
		udlr[1][p.y]++;
	if (rec[2])
		udlr[2][p.x]++;
	if (rec[3])
		udlr[3][p.x]++;
}

void	substract_rc(t_point p, int *rec, int (*map)[9], int (*udlr)[9])
{
	int	i;

	i = 0;
	while (i < 4)
		rec[i++] = 0;
	if (is_sub_up(p, map))
	{
		udlr[0][p.y]--;
		rec[0] = 1;
	}
	if (is_sub_down(p, map))
	{
		udlr[1][p.y]--;
		rec[1] = 1;
	}
	if (is_sub_left(p, map))
	{
		udlr[2][p.x]--;
		rec[2] = 1;
	}
	if (is_sub_right(p, map))
	{
		udlr[3][p.x]--;
		rec[3] = 1;
	}
}
