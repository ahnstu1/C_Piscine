/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:40:40 by hahn              #+#    #+#             */
/*   Updated: 2021/10/10 14:40:46 by hahn             ###   ########.fr       */
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
			if ((w == 1 || w == x) && (l == 1 || l == y))
				ft_putchar('o');
			else if (w == 1 || w == x)
				ft_putchar('|');
			else if (l == 1 || l == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			w++;
		}
		if (x != 0)
			ft_putchar('\n');
		l++;
	}
}
