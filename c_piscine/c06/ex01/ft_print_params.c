/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:55:05 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 20:15:36 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (--argc)
	{
		while (*argv[idx])
			write(1, argv[idx]++, 1);
		idx++;
		write(1, "\n", 1);
	}
}
