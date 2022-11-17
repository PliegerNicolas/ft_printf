/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/17 15:14:32 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_char_count(long int nb)
{
	size_t	char_count;

	char_count = 0;
	if (nb < 0)
		char_count++;
	while (nb >= 1 || nb < 0)
	{
		nb /= 10;
		char_count++;
	}
	return (char_count);
}

static void	ft_double_join(char *s, size_t char_count, double nb,
	const size_t precision)
{
	char	*temp;
	size_t	i;

	nb *= ft_power(10, precision);
	temp = ft_itoa(nb);
	if (!temp)
		return ;
	i = 0;
	while (i < char_count)
	{
		s[i] = temp[i];
		i++;
	}
	s[i++] = '.';
	while (i < char_count + precision + 1)
	{
		s[i] = temp[i - 1];
		i++;
	}
	s[i] = '\0';
	free(temp);
}

char	*ft_dtoa(const double nb, const size_t precision)
{
	char	*ret;
	size_t	char_count;

	char_count = ft_char_count(nb);
	ret = (char *)malloc((char_count + precision + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_double_join(ret, char_count, nb, precision);
	return (ret);
}
