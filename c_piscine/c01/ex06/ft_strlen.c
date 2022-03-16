/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:30:13 by hahn              #+#    #+#             */
/*   Updated: 2021/10/16 10:11:26 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	char	*strPointer;
	int		output;

	strPointer = str;
	output = 0;
	while (*strPointer != '\0')
	{
		output++;
		strPointer++;
	}
	return (output);
}
