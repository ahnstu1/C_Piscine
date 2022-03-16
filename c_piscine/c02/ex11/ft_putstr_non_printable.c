/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:28 by hahn              #+#    #+#             */
/*   Updated: 2021/10/19 18:18:30 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hexadecimals;
	unsigned char	input;
	int				idx;

	idx = 0;
	hexadecimals = "0123456789abcdef";
	while (str[idx] != '\0')
	{
		input = str[idx];
		if (str[idx] >= 32 && str[idx] <= 126)
			write(1, &input, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hexadecimals[input / 16], 1);
			write(1, &hexadecimals[input % 16], 1);
		}
		idx++;
	}
}
