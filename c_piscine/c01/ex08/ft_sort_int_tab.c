/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:36:34 by hahn              #+#    #+#             */
/*   Updated: 2021/10/16 10:09:41 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	*arrPointer;
	int	repeatCount;
	int	inRepeatCount;
	int	store;

	repeatCount = 0;
	while (++repeatCount < size)
	{
		arrPointer = tab;
		inRepeatCount = 0;
		while (inRepeatCount++ < size - 1)
		{
			if (*arrPointer > *(arrPointer + 1))
			{
				store = *arrPointer;
				*arrPointer = *(arrPointer + 1);
				*(arrPointer + 1) = store;
			}
			arrPointer++;
		}
	}
}
