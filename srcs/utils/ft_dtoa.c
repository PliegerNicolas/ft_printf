/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/17 17:26:44 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_double_join(char *s, size_t char_count, double nb,
	const size_t precision)
{
	char	*temp;
	size_t	i;

	temp = ft_itoa(nb * ft_power(10, precision));
	if (!temp)
		return ;
	i = 0;
	while (i < char_count)
	{
		if (temp[i])
			s[i] = temp[i];
		else
			s[i] = '0';
		i++;
	}
	s[i] = '.';
	while (++i < char_count + precision + 1)
	{
		if (temp[i - 1])
			s[i] = temp[i - 1];
		else
			s[i] = '0';
	}
	s[i] = '\0';
	free(temp);
}

char	*ft_dtoa(const double nb, const size_t precision)
{
	char	*ret;
	size_t	char_count;

	char_count = ft_charcount(nb);
	ret = (char *)malloc((char_count + precision + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_double_join(ret, char_count, nb, precision);
	return (ret);
}
