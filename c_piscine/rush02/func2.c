/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:02:42 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:30:34 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head02.h"

char	*init(int argc, char **argv, unsigned int *c, char *file)
{
	if (argc == 2)
		*c = ft_atoi(argv[1]);
	else if (argc == 3)
	{
		*c = ft_atoi(argv[2]);
		file = argv[1];
	}
	return (file);
}

void	sep_num(unsigned int num, t_dic *a)
{
	unsigned int	keymult;

	if (num == 0)
	{
		finder(0, a);
		return ;
	}
	while (num >= 1000)
	{
		keymult = getmult(num);
		ft_print(keymult, num / keymult, a);
		num %= keymult;
	}
	ft_print(1, num, a);
}
