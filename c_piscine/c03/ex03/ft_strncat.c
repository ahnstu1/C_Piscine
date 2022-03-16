/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:48:51 by hahn              #+#    #+#             */
/*   Updated: 2021/10/18 23:47:17 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*output;

	output = dest;
	while (*dest)
		dest++;
	while (nb-- && *src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (output);
}
