/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:11:25 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 17:02:19 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb2(void)
{
	int		first_field;
	int		second_field;
	char	output;

	first_field = 0;
	while (first_field != 99)
	{
		second_field = first_field;
		while (++second_field != 100)
		{
			output = first_field / 10 + '0';
			write(1, &output, 1);
			output = first_field % 10 + '0';
			write(1, &output, 1);
			write(1, " ", 1);
			output = second_field / 10 + '0';
			write(1, &output, 1);
			output = second_field % 10 + '0';
			write(1, &output, 1);
			if (first_field != 98)
				write(1, ", ", 2);
		}
		first_field++;
	}
}
