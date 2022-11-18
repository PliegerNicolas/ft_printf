/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:13:27 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 10:15:18 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

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
