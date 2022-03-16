/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:39:58 by hahn              #+#    #+#             */
/*   Updated: 2021/10/19 15:26:34 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	f_i;

	i = -1;
	if (*to_find == '\0')
		return (str);
	while (str[++i] != '\0')
	{
		f_i = 0;
		while (str[i + f_i] == to_find[f_i] && to_find[f_i] != '\0')
			f_i++;
		if (to_find[f_i] == '\0')
			return (&str[i]);
	}
	return (0);
}
