/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 17:55:24 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_precision_printer()
{
	
}

char	*ft_dtoa(const double nb, size_t precision)
{
	char		*ret;
	size_t		char_count;
	double		nb_cpy;

	char_count = ft_precision_charcount(nb, precision);
	ret = malloc((char_count + 1) * sizeof(char));
	ret[char_count--] = '\0';
	if (nb < 0 || ft_isnegativezero(nb))
		nb_cpy = -nb;
	else
		nb_cpy = nb;
	nb_cpy *= ft_power(10, precision + 1);
	if (ft_dmod(nb_cpy, 10) >= 5)
	{
		nb_cpy /= 10;
		nb_cpy++;
	}
	else
		nb_cpy /= 10;
	if (precision)
	{
		while (precision)
		{
			ret[char_count--] = ft_dmod(nb_cpy, 10) + '0';
			nb_cpy /= 10.0;
			precision--;
		}
		ret[char_count--] = '.';
	}
	while (nb_cpy >= 1)
	{
		ret[char_count--] = ft_dmod(nb_cpy, 10) + '0';
		nb_cpy /= 10.0;
	}
	if ((unsigned long long int)nb == 0)
		ret[char_count--] = '0';
	if (nb < 0 || ft_isnegativezero(nb))
		ret[char_count--] = '-';
	return (ret);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s = ", ft_dtoa(-123.123, 3));
	printf("%.3f\n", -123.123);
	printf("%s = ", ft_dtoa(-123456789.123456789, 6));
	printf("%f\n", -123456789.123456789);

	printf("%s = ", ft_dtoa(123456789.123456789, 6));
	printf("%f\n", 123456789.123456789);

	printf("%s = ", ft_dtoa(123456789123456789.123456789123456789, 12));
	printf("%.12f\n", 123456789123456789.123456789123456789); // error

	printf("%s = ", ft_dtoa(123456789.1234, 0));
	printf("%.0f\n", 123456789.1234);

	printf("%s = ", ft_dtoa(0.0, 0));
	printf("%.0f\n", 0.0);

	printf("%s = ", ft_dtoa(-0., 0));
	printf("%.0f\n", -0.);

	printf("%s = ", ft_dtoa(-0., 5));
	printf("%.5f\n", -0.);

	printf("%s = ", ft_dtoa(0., 12));
	printf("%.12f\n", 0.);
	return (0);
}
*/
