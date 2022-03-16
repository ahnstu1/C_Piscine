/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:18:02 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 11:38:03 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	result = 0;
	while (++result)
	{
		if (result * result == nb)
			break ;
		if (result * result > nb || result > 46340)
			return (0);
	}
	return (result);
}
