/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:58:23 by hahn              #+#    #+#             */
/*   Updated: 2021/10/16 10:11:02 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)
{
	char	*strPointer;

	strPointer = str;
	while (*strPointer != '\0')
	{
		write(1, strPointer, 1);
		strPointer++;
	}
}
