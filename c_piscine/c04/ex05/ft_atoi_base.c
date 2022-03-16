/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:56:21 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 17:34:09 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
{
	int	idx;
	int	cmp_idx;

	idx = 0;
	if (base[idx] == '\0' || base[idx + 1] == '\0')
		return (0);
	while (base[idx])
	{
		cmp_idx = idx;
		while (base[++cmp_idx])
		{
			if (base[idx] == base[cmp_idx] || base[cmp_idx] == '\n'
				|| base[cmp_idx] == '-' || base[cmp_idx] == '\v'
				|| base[cmp_idx] == '\t' || base[cmp_idx] == '\f'
				|| base[cmp_idx] == ' ' || base[cmp_idx] == '\r'
				|| base[cmp_idx] == '+')
				return (0);
		}
		idx++;
	}
	return (idx);
}

int	convert_decimal(char *str, char *base, int count)
{
	int	idx;
	int	output;

	output = 0;
	while (*str)
	{
		idx = 0;
		while (base[idx])
		{
			if (*str == base[idx])
			{
				output *= count;
				output += idx;
				break ;
			}
			idx++;
		}
		if (!base[idx])
			break ;
		str++;
	}
	return (output);
}

int	ft_atoi_base(char *str, char *base)
{
	int	output;
	int	count;
	int	sign;

	sign = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	count = base_check(base);
	if (!count || !*str)
		return (0);
	output = convert_decimal(str, base, count);
	if (sign % 2)
		output *= -1;
	return (output);
}
