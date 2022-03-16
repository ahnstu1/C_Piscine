/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:34:05 by hahn              #+#    #+#             */
/*   Updated: 2021/10/12 14:13:22 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	int		result;
	char	output;

	result = 11;
	while (result != 789)
	{
		if (result / 10 % 10 == 8 && result % 10 == 9)
			result += 34 + result / 100 * 11;
		else if (result % 10 == 9)
			result += 10 - 7 + result / 10 % 10;
		else
			result++;
		output = result / 100 + '0';
		write(1, &output, 1);
		output = result / 10 % 10 + '0';
		write(1, &output, 1);
		output = result % 10 + '0';
		write(1, &output, 1);
		if (result != 789)
			write(1, ", ", 2);
	}
}
