/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:46:53 by hahn              #+#    #+#             */
/*   Updated: 2021/10/20 01:38:16 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	print_hexa(int input)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[input], 1);
}

void	memory_print_hexa(long long int input, unsigned int count)
{
	if (count > 0)
		memory_print_hexa(input / 16, --count);
	print_hexa(input % 16);
}

void	memory_print_str_hexa(unsigned char *input, unsigned char *count)
{
	int				idx;
	unsigned int	output;

	idx = 0;
	while (idx < 16)
	{
		output = (unsigned int)*(input + idx);
		if (input + idx < count)
		{
			print_hexa(output / 16);
			print_hexa(output % 16);
		}
		else
			write(1, "  ", 2);
		if (idx++ % 2)
			write(1, " ", 1);
	}
}

void	memory_print_str(unsigned char *input, unsigned char *count)
{
	int	idx;

	idx = 0;
	while (idx < 16 && input + idx < count)
	{
		if (!(32 <= *(input + idx) && *(input + idx) <= 126))
			write(1, ".", 1);
		else
			write(1, input + idx, 1);
		idx++;
	}
}

void	*ft_print_memory(void	*addr, unsigned int size)
{
	unsigned char	*count;
	unsigned char	*input;

	input = (unsigned char *)addr;
	count = input + size;
	while (input < count)
	{
		memory_print_hexa((long long int)input, 15);
		write(1, ": ", 2);
		memory_print_str_hexa(input, count);
		memory_print_str(input, count);
		write(1, "\n", 1);
		input += 16;
	}
	return (addr);
}
