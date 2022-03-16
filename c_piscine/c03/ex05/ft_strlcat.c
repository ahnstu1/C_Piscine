/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:26:43 by hahn              #+#    #+#             */
/*   Updated: 2021/10/19 15:24:47 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_l;
	unsigned int	s_l;

	d_l = 0;
	s_l = 0;
	while (*dest)
	{
		dest++;
		d_l++;
	}
	while (size > d_l + s_l + 1 && *src != '\0')
	{
		*(dest++) = *(src++);
		s_l++;
	}
	*dest = '\0';
	while (*src)
	{
		s_l++;
		src++;
	}
	if (size <= d_l)
		return (s_l + size);
	else
		return (s_l + d_l);
}
