/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:13:27 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 14:07:46 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_charcount(long long int nb)
{
	size_t	char_count;

	char_count = 0;
	if (nb < 0)
		char_count++;
	if (nb == 0)
		return (++char_count);
	while (nb >= 1 || nb < 0)
	{
		nb /= 10;
		char_count++;
	}
	return (char_count);
}

char	*ft_llitoa(long long int n)
{
	char					*s;
	size_t					len;
	size_t					i;
	unsigned long long int	nb;

	len = ft_charcount(n);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	s[len] = '\0';
	if (n == 0)
		s[--len] = '0';
	nb = (unsigned long long int)n;
	if (n < 0)
	{
		nb *= -1;
		s[i++] = '-';
	}
	while (len > i)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
