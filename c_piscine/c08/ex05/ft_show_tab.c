/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:44:00 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 15:33:06 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <unistd.h>

void	print_number(int nbr)
{
	char	output;

	if (nbr >= 10)
		print_number(nbr / 10);
	output = nbr % 10 + '0';
	write(1, &output, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	while (par -> str)
	{
		idx = 0;
		write(1, par -> str, par -> size);
		write(1, "\n", 1);
		print_number(par -> size);
		write(1, "\n", 1);
		while (par -> copy[idx])
			write(1, &par -> copy[idx++], 1);
		write(1, "\n", 1);
		par++;
	}
}
