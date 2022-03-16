/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:44:55 by hahn              #+#    #+#             */
/*   Updated: 2021/10/27 11:39:43 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_check(char *input)
{
	int	idx;
	int	cmp_idx;

	idx = -1;
	if (!(input[0] && input[1]))
		return (0);
	while (input[++idx])
	{
		cmp_idx = idx;
		while (input[++cmp_idx])
		{
			if (input[idx] == input[cmp_idx])
				return (0);
			if (input[cmp_idx] == '+' || input[cmp_idx] == '-'
				|| input[cmp_idx] == '\t' || input[cmp_idx] == '\n'
				|| input[cmp_idx] == '\f' || input[cmp_idx] == '\v'
				|| input[cmp_idx] == '\r' || input[cmp_idx] == ' ')
				return (0);
		}
	}
	return (idx);
}

int	covert_decimal(char *nbr, char *base_from, int length, int sign)
{
	int	idx;
	int	output;

	output = 0;
	while (*nbr)
	{
		idx = -1;
		while (base_from[++idx])
		{
			if (*nbr == base_from[idx])
			{
				output *= length;
				if (sign % 2)
					output -= idx;
				else
					output += idx;
				break ;
			}
		}
		if (idx == length)
			return (output);
		nbr++;
	}
	return (output);
}

int	result_size(int nbr, int length, int sign)
{
	int	result;

	result = 0;
	if (!nbr)
		return (2);
	while (nbr)
	{
		nbr /= length;
		result++;
	}
	if (sign % 2)
		result++;
	return (result + 1);
}

char	*convert_to(int nbr, char *base, int length, char *result)
{
	int	sign;

	*(result--) = '\0';
	sign = 0;
	if (nbr < 0)
		sign = 1;
	if (!nbr)
	{
		*result = base[0];
		return (result);
	}
	while (nbr)
	{
		if (sign)
			*(result--) = base[-(nbr % length)];
		else
			*(result--) = base[nbr % length];
		nbr /= length;
	}
	if (sign)
	{
		*result = '-';
		return (result);
	}
	return (result + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		sign;
	int		decimal;
	int		size;

	sign = 0;
	if (!(base_check(base_from) && base_check(base_to)))
		return (0);
	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\r' || *nbr == '\v'
		|| *nbr == '\n' || *nbr == '\f')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign++;
		nbr++;
	}
	decimal = covert_decimal(nbr, base_from, base_check(base_from), sign);
	size = result_size(decimal, base_check(base_to), sign);
	result = (char *)malloc(sizeof(char) * size);
	convert_to(decimal, base_to, base_check(base_to), result + size - 1);
	return (result);
}
