/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:15:20 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 11:33:43 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 0;
	if (power == 0)
		result = 1;
	else if (power == 1)
		result = nb;
	else if (power > 1)
		result = nb * ft_recursive_power(nb, --power);
	else
		result = 0;
	return (result);
}
