/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:38:32 by hahn              #+#    #+#             */
/*   Updated: 2021/10/26 17:01:03 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	print(int *arr_pointer, int n)
{
	char	output;

	while (--n > -1)
	{
		output = *arr_pointer + '0';
		arr_pointer++;
		write(1, &output, 1);
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		arr[10];

	i = n;
	while (i-- > 0)
		arr[i] = i;
	while (arr[0] != 10 - n)
	{
		i = n - 1;
		print(&arr[0], n);
		arr[n - 1]++;
		if (arr[n - 1] == 10 && i--)
			while (arr[i] == i - n + 10)
				i--;
		while (n != 1 && i++ < n - 1)
			arr[i] = ++arr[i - 1];
		if (n != 1 && arr[n - 1] == arr[n - 2])
			arr[n - 1] = arr[n - 2] + 1;
		write(1, ", ", 2);
	}
	print(&arr[0], n);
}
