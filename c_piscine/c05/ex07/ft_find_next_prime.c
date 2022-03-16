/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:20:15 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 11:47:08 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	div;

	if (nb < 3)
		return (2);
	if (!(nb % 2))
		nb++;
	while (nb > 2)
	{
		div = 1;
		while (++div <= nb / 2)
		{
			if (nb % div == 0)
				break ;
			if (div > 46340)
				break ;
		}
		if (nb % div != 0)
			return (nb);
		nb += 2;
	}
	return (nb);
}
