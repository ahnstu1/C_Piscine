/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:00:15 by hahn              #+#    #+#             */
/*   Updated: 2021/10/25 15:52:02 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*output;
	int	idx;

	idx = 0;
	if (min >= max)
		return (0);
	output = (int *)malloc(sizeof(int) * (max - min));
	if (!output)
		return (0);
	while (min < max)
		output[idx++] = min++;
	return (output);
}
