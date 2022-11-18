/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 13:23:24 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_precision_charcount(const double nb, const size_t precision)
{
	size_t			char_count;
	long double		n;

	char_count = 0;
	if (nb < 0)
	{
		char_count++;
		n = -nb;
	}
	else
		n = nb;
	if (nb < 1 && nb > -1)
		return (++char_count + precision + 1);
	while (n >= 1 || n < 0)
	{
		n /= 10;
		char_count++;
	}
	return (char_count + precision + 1);
}

char	*ft_dtoa(const double nb, size_t precision)
{
	char					*ret;
	size_t					char_count;
	size_t					ullint_nb_len;
	unsigned long long int	ullint_nb;
	double					nb2;
	size_t					i;

	char_count = ft_precision_charcount(nb, precision);
	ret = malloc((char_count + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ullint_nb_len = char_count - precision - 1;
	ret[char_count--] = '\0';
	if ((unsigned long long int)nb == 0)
		ret[0] = '0';
	if (nb < 0)
	{
		ret[0] = '-';
		ullint_nb = (unsigned long long int)(-nb);
		nb2 = nb + (double)ullint_nb;
	}
	else
	{
		ullint_nb = (unsigned long long int)nb;
		nb2 = nb - (double)ullint_nb;
	}
	if (ullint_nb == 0 && nb < 0)
	{
		ret[0] = '-';
		ret[1] = '0';
	}
	while (ullint_nb > 0)
	{
		ret[--ullint_nb_len] = (ullint_nb % 10) + '0';
		ullint_nb /= 10;
	}
	ret[char_count - precision] = '.';
	if (nb2 < 0)
		nb2 *= -1;
	nb2 *= ft_power(10, precision + 1);
	if (((unsigned long long int)nb2 % 10) % 10 >= 5)
	{
		nb2 /= 10;
		nb2++;
	}
	else
		nb2 /= 10;
	if (nb2 < 0)
		nb2 *= -1;
	i = 0;
	while (nb2 >= 1 || i < precision)
	{
		ret[char_count--] = (unsigned long long int)nb2 % 10 + '0';
		nb2 /= 10;
		i++;
	}
	return (ret);
}

int	main(void)
{
	char			*s;
	double			nb;
	size_t			precision;

	nb = 123456789123.1235123512351235;
	precision = 10;
	s = ft_dtoa(nb, precision);
	printf("%s\n", s);
	printf("%.10f\n", nb);
	return (0);
}
