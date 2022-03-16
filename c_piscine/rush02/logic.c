/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:03:03 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:03:05 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head02.h"

char	*ft_getchar(char *file)
{
	int		fd;
	int		i;
	char	c[1];
	char	*d;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, c, 1))
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	d = (char *) malloc(i * 10);
	read(fd, d, i);
	close(fd);
	return (d);
}

void	getkey(t_dic *a, char *d)
{
	int		i;
	int		j;
	int		k;
	char	*b;

	i = 0;
	k = 0;
	b = (char *) malloc(ft_strlen(d));
	while (d[i])
	{
		j = 0;
		while (d[i] && d[i] < 33)
			i++;
		if (d[i] == '+' || d[i] == '-')
			b[j++] = d[i++];
		while ('0' <= d[i] && d[i] <= '9')
			b[j++] = d[i++];
		b[j] = 0;
		a[k++].key = ft_atoi(b);
		while (d[i] && d[i] != '\n')
			i++;
	}
	free (b);
}

void	getvalue(t_dic *a, char *d)
{
	int		i;
	int		j;
	int		k;
	char	*b;

	i = 0;
	k = 0;
	b = (char *) malloc(ft_strlen(d) * 10);
	while (d[i])
	{
		j = 0;
		while (d[i] && d[i] != ':')
			i++;
		if (d[i] == ':')
			i++;
		while (d[i] == ' ')
			i++;
		while (32 <= d[i] && d[i] < 127)
			b[j++] = d[i++];
		b[j] = 0;
		a[k++].value = b;
		b += j + 1;
		i++;
	}
}

t_dic	*logic(t_dic *a, char *file)
{
	char	*d;

	d = ft_getchar(file);
	a = (t_dic *)malloc(sizeof(t_dic) * ft_strlen(d) + 1);
	getvalue(a, d);
	getkey(a, d);
	free(d);
	return (a);
}
