/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:56:06 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 17:38:12 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	idx;
	int	cmp_idx;

	idx = 0;
	if (base[idx] == '\0' || base[idx + 1] == '\0')
		return (0);
	while (base[idx])
	{
		if (base[idx] == '-' || base[idx] == '+')
			return (0);
		idx++;
	}
	idx = 0;
	while (base[idx])
	{
		cmp_idx = idx;
		while (base[++cmp_idx])
		{
			if (base[idx] == base[cmp_idx])
				return (0);
		}
		idx++;
	}
	return (idx);
}

void	negative_print(int nbr, int count, char *base)
{
	int	output;

	output = nbr % count;
	output *= -1;
	if (nbr <= -count)
		negative_print(nbr / count, count, base);
	write(1, &base[output], 1);
}

void	base_print(int nbr, int count, char *base)
{
	if (nbr >= count)
		base_print(nbr / count, count, base);
	write(1, &base[nbr % count], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	count;

	count = base_check(base);
	if (!count)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		negative_print(nbr, count, base);
	}
	else
		base_print(nbr, count, base);
}
