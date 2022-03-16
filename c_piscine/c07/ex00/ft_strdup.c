/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:53:52 by hahn              #+#    #+#             */
/*   Updated: 2021/10/27 11:37:54 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	int		idx;
	char	*cpy;

	size = 0;
	idx = -1;
	while (src[++idx])
		size++;
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (0);
	idx = -1;
	while (++idx < size)
		cpy[idx] = src[idx];
	cpy[idx] = '\0';
	return (cpy);
}
