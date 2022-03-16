/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:02:16 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:02:22 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

unsigned int	ft_power_dec(int power)
{
	unsigned int	n;

	n = 1;
	while (power--)
		n *= 10;
	return (n);
}

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	neg;
	unsigned int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (!('0' <= str[i] && str[i] <= '9'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (str[i] != 0)
		return (-1);
	return (result * neg);
}

void	burn_dic(t_dic *a)
{
	int	i;

	i = 0;
	while (a[i].key)
		free(a[i++].value);
	free(a);
}
