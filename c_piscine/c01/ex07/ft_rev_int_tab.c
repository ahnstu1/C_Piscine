/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:54:59 by hahn              #+#    #+#             */
/*   Updated: 2021/10/16 10:03:17 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	store;
	int	*Arr;

	index = 0;
	Arr = tab;
	while (index != size / 2)
	{
		store = *Arr;
		*Arr = *(tab + size - 1 - index);
		*(tab + size - 1 - index++) = store;
		Arr++;
	}
}
