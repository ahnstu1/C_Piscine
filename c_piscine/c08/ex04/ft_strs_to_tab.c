/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:08:12 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 15:29:25 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*output;
	int			idx;
	int			length;
	int			cpy_idx;

	idx = -1;
	output = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!output)
		return (0);
	while (++idx < ac)
	{
		length = 0;
		cpy_idx = -1;
		output[idx].str = av[idx];
		while (output[idx].str[length])
			length++;
		output[idx].size = length;
		output[idx].copy = (char *)malloc(sizeof(char) * length + 1);
		while (av[idx][++cpy_idx])
			output[idx].copy[cpy_idx] = av[idx][cpy_idx];
		output[idx].copy[cpy_idx] = '\0';
	}
	output[idx].str = 0;
	return (output);
}
