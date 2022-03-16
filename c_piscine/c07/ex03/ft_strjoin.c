/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:03:54 by hahn              #+#    #+#             */
/*   Updated: 2021/10/25 15:52:19 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_calc(char *input)
{
	int	idx;

	idx = 0;
	while (input[idx])
		idx++;
	return (idx);
}

void	make_str(int size, char **strs, char *sep, char *result)
{
	int	idx;
	int	in_idx;
	int	sep_idx;

	idx = -1;
	while (++idx < size)
	{
		sep_idx = 0;
		in_idx = 0;
		while ((char)strs[idx][in_idx])
			*(result++) = (char)strs[idx][in_idx++];
		if (idx < size - 1)
		{
			while ((char)sep[sep_idx])
				*(result++) = (char)sep[sep_idx++];
		}
	}
	*result = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		o_size;
	int		idx;

	idx = -1;
	o_size = 0;
	if (!size)
	{
		result = (char *)malloc(sizeof(char) * 1);
		return (result);
	}
	while (++idx < size - 1)
	{
		o_size += size_calc(strs[idx]);
		o_size += size_calc(sep);
	}
	o_size += size_calc(strs[idx]);
	result = (char *)malloc(sizeof(char) * (o_size + 1));
	if (!result)
		return (0);
	make_str(size, strs, sep, result);
	return (result);
}
