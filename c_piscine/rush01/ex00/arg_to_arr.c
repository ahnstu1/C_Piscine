/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:51:34 by mypark            #+#    #+#             */
/*   Updated: 2021/10/17 23:15:32 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	split_str(char *str, int *num)
{
	int		i;
	char	*num_check;

	i = 0;
	num_check = str;
	while (*num_check != '\0')
	{
		if (*num_check >= '0' && *num_check <= '9')
			i++;
		num_check++;
	}
	if (i > 36)
		return (i);
	i = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '9')
			num[i++] = (*str) - '0';
		if (!(*str == ' ' || *str == '\n' || *str == '\t'
				|| (*str >= '1' && *str <= '9')))
			return (0);
		str++;
	}
	return (i);
}

int	arg_to_arr(char *str, int (*udlr)[9])
{
	int	i;
	int	j;
	int	cnt;
	int	num[36];

	cnt = split_str(str, num);
	if (cnt > 36)
		return (cnt);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < cnt / 4)
		{
			udlr[i][j] = num[i * cnt / 4 + j];
			j++;
		}
		i++;
	}
	return (cnt);
}
