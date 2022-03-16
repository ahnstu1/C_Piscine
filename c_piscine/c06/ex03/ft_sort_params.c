/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:57:37 by hahn              #+#    #+#             */
/*   Updated: 2021/10/24 20:13:11 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	argv_sort(char **argv1, char **argv2)
{
	int		idx;
	char	*store;

	idx = 0;
	while ((*argv1)[idx] && (*argv2)[idx])
	{
		if ((*argv1)[idx] != (*argv2)[idx])
			break ;
		idx++;
	}
	if ((*argv1)[idx] - (*argv2)[idx] > 0)
	{
		store = *argv1;
		*argv1 = *argv2;
		*argv2 = store;
	}
}

void	argv_print(char *argv)
{
	while (*argv)
		write(1, argv++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	sort_count;

	sort_count = 2;
	if (argc == 2)
	{
		while (*argv[1])
			write(1, argv[1]++, 1);
		write(1, "\n", 1);
	}
	else
	{
		while (sort_count++ < argc)
		{
			idx = 1;
			while (idx < argc - 1)
			{
				argv_sort(&argv[idx], &argv[idx + 1]);
				idx++;
			}
		}
		idx = 0;
		while (++idx < argc)
			argv_print(argv[idx]);
	}
}
