/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:35:52 by hahn              #+#    #+#             */
/*   Updated: 2021/10/27 17:12:06 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	charset_check(char input, char *charset)
{
	int	idx;

	idx = -1;
	while (charset[++idx])
		if (input == charset[idx])
			return (0);
	return (1);
}

int	total_length(char *str, char *charset)
{
	int	result;

	result = 0;
	while (*str)
	{
		while (*str && !charset_check(*str, charset))
			str++;
		if (*str)
			result++;
		while (*str && charset_check(*str, charset))
			str++;
	}
	return (result);
}

int	sub_length(char *str, char *charset)
{
	int	result;

	result = 0;
	while (*str)
	{
		while (*str && !charset_check(*str, charset))
			str++;
		while (*str && charset_check(*str, charset))
		{
			result++;
			str++;
		}
		break ;
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		length;
	int		idx;
	int		in_idx;

	idx = -1;
	length = total_length(str, charset);
	output = (char **)malloc(sizeof(char *) * (length + 1));
	if (!output)
		return (0);
	while (*str)
	{	
		in_idx = -1;
		length = sub_length(str, charset);
		while (*str && !charset_check(*str, charset))
			str++;
		if (!*str)
			return (output);
		output[++idx] = (char *)malloc(sizeof(char) * (length + 1));
		while (++in_idx < length)
			output[idx][in_idx] = *(str++);
		output[idx][in_idx] = '\0';
	}
	output[idx + 1] = 0;
	return (output);
}
