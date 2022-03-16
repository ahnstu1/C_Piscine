/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:02:54 by bseo              #+#    #+#             */
/*   Updated: 2021/10/24 23:02:56 by bseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD02_H
# define HEAD02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct Dictionary{
	unsigned int	key;
	char			*value;
}t_dic;

int				ft_strlen(char *str);
void			ft_putstr(char *str);
unsigned int	ft_power_dec(int power);
unsigned int	ft_atoi(char *str);
char			*ft_getchar(char *file);
void			getkey(t_dic *a, char *d);
void			getvalue(t_dic *a, char *d);
char			*init(int argc, char **argv, unsigned int *c, char *file);
t_dic			*logic(t_dic *a, char *file);
void			burn_dic(t_dic *a);
void			sep_num(unsigned int num, t_dic *a);
void			finder(unsigned int nb, t_dic *a);
unsigned int	getmult(unsigned int key);
int				getnbr(int key);
void			ft_print(unsigned int keymult, unsigned int d, t_dic *a);

#endif
