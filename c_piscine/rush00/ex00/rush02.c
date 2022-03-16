/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:51 by hahn              #+#    #+#             */
/*   Updated: 2021/10/10 14:40:54 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	w;
	int	l;

	l = 1;
	while (l <= y)
	{
		w = 1;
		while (w <= x)
		{
			if ((w == 1 && l == 1) || (w == x && l == 1))
				ft_putchar('A');
			else if ((w == 1 && l == y) || (w == x && l == y))
				ft_putchar('C');
			else if (l == 1 || w == 1 || l == y || w == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			w++;
		}
		if (x != 0)
			ft_putchar('\n');
		l++;
	}
}
