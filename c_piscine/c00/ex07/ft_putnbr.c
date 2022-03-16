/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:29:33 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 17:01:27 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	int		input;
	int		index;
	int		input_arr[10];
	char	output;

	input = nb;
	index = 0;
	if (input == 0)
		write(1, "0", 1);
	else if (input < 0)
		write(1, "-", 1);
	while (input != 0)
	{
		input_arr[index++] = input % 10;
		input /= 10;
	}
	while (--index >= 0)
	{
		if (input_arr[index] < 0)
			input_arr[index] *= -1;
		output = input_arr[index] + '0';
		write(1, &output, 1);
	}
}
