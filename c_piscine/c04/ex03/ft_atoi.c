/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:55:40 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 21:20:32 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	output;
	int	sign;

	sign = 0;
	output = 0;
	while (*str == '\n' || *str == '\v' || *str == '\f' || *str == '\t'
		|| *str == ' ' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output *= 10;
		output += *str - '0';
		str++;
	}
	if (sign % 2)
		output *= -1;
	return (output);
}
