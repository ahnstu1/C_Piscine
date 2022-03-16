/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:01:44 by hahn              #+#    #+#             */
/*   Updated: 2021/10/27 14:11:08 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*in_range;
	int	idx;
	int	store;

	idx = 0;
	store = min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	in_range = (int *)malloc(sizeof(int) * (max - min));
	if (!in_range)
		return (-1);
	while (min < max)
		in_range[idx++] = min++;
	*range = in_range;
	return (max - store);
}
