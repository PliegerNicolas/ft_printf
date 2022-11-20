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

static double	ft_precision_printer(char *ret, const double nb,
								size_t *precision, size_t *char_count)
{
	double		nb_cpy;

	if (nb < 0 || ft_isnegativezero(nb))
		nb_cpy = -nb;
	else
		nb_cpy = nb;
	nb_cpy *= ft_power(10, (*precision) + 1);
	if (ft_dmod(nb_cpy, 10) >= 5)
	{
		nb_cpy /= 10;
		nb_cpy++;
	}
	else
		nb_cpy /= 10;
	if (*precision)
	{
		while (*precision)
		{
			ret[(*char_count)--] = ft_dmod(nb_cpy, 10) + '0';
			nb_cpy /= 10.0;
			(*precision)--;
		}
		ret[(*char_count)--] = '.';
	}
	return (nb_cpy);
}

char	*ft_dtoa(const double nb, size_t precision)
{
	char		*ret;
	size_t		char_count;
	double		nb_cpy;

	char_count = ft_precision_charcount(nb, precision);
	ret = malloc((char_count + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[char_count--] = '\0';
	nb_cpy = ft_precision_printer(ret, nb, &precision, &char_count);
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
