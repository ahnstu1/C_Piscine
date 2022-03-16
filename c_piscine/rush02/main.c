/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:20:25 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:35:12 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:03:11 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:03:12 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head02.h"

int	getnbr(int key)
{
	if (20 < key)
		return ((key / 10) * 10);
	else if (0 <= key && key <= 19)
		return (key);
	else
		return (0);
}

unsigned int	getmult(unsigned int key)
{
	unsigned int	nbr;
	int				i;

	nbr = key;
	i = 0;
	while ((nbr / 10) > 0)
	{
		nbr /= 10;
		i++;
	}
	if (i < 2)
		return (1);
	if (i == 2)
		return (100);
	if (i >= 3)
	{
		if (i % 3 == 0)
			return (ft_power_dec(i));
		else
			return (ft_power_dec(i - (i % 3)));
	}
	return (0);
}

void	finder(unsigned int nb, t_dic *a)
{
	int	i;

	i = 0;
	while (a[i].value)
	{
		if (nb == a[i].key)
		{
			ft_putstr(a[i].value);
			write(1, " ", 1);
			return ;
		}
		i++;
	}
	write (1, "Dict Error\n", 11);
}

void	ft_print(unsigned int keymult, unsigned int d, t_dic *a)
{
	if (d >= 100)
	{
		finder(d / 100, a);
		finder(100, a);
		d = d % 100;
	}
	if (1 <= d && d <= 20)
		finder(d, a);
	else
	{
		if (d / 10 != 0)
			finder(d / 10 * 10, a);
		if (d % 10 != 0)
			finder(d % 10, a);
	}
	if (keymult > 1)
		finder(keymult, a);
}

int	main(int argc, char	**argv)
{
	t_dic			*a;
	unsigned int	num;
	char			*file;

	file = "numbers.dict.txt";
	a = 0;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	file = init (argc, argv, &num, file);
	a = logic(a, file);
	if (num < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	sep_num(num, a);
	burn_dic(a);
	return (0);
}
