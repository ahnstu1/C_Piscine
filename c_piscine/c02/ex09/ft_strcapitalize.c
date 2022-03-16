/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:07:56 by hahn              #+#    #+#             */
/*   Updated: 2021/10/20 23:01:52 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += 32;
		idx++;
	}
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			if (idx == 0 || !((str[idx - 1] >= 'a' && str[idx - 1] <= 'z')
					|| (str[idx - 1] >= 'A' && str[idx - 1] <= 'Z')
					|| (str[idx - 1] >= '0' && str[idx - 1] <= '9')))
				str[idx] -= 32;
		}
		idx++;
	}
	return (str);
}
