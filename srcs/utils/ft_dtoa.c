/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 14:01:46 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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

static unsigned long long int	ft_precomma(char *ret, const double nb,
										double *reduced_nb, size_t *char_count)
{
	unsigned long long int	ullint_nb;

	ret[(*char_count)--] = '\0';
	if ((unsigned long long int)nb == 0)
		ret[0] = '0';
	if (nb < 0)
	{
		ret[0] = '-';
		ullint_nb = (unsigned long long int)(-nb);
		*reduced_nb = nb + (double)ullint_nb;
	}
	else
	{
		ullint_nb = (unsigned long long int)nb;
		*reduced_nb = nb - (double)ullint_nb;
	}
	if (ullint_nb == 0 && nb < 0)
	{
		ret[0] = '-';
		ret[1] = '0';
	}
	return (ullint_nb);
}

static void	ft_aftercomma(char *ret, double reduced_nb, size_t char_count,
					const size_t precision)
{
	size_t		i;

	if (reduced_nb < 0)
		reduced_nb *= -1;
	reduced_nb *= ft_power(10, precision + 1);
	if (((unsigned long long int)reduced_nb % 10) % 10 >= 5)
	{
		reduced_nb /= 10;
		reduced_nb++;
	}
	else
		reduced_nb /= 10;
	if (reduced_nb < 0)
		reduced_nb *= -1;
	i = 0;
	while (reduced_nb >= 1 || i < precision)
	{
		ret[char_count--] = (unsigned long long int)reduced_nb % 10 + '0';
		reduced_nb /= 10;
		i++;
	}
}

char	*ft_dtoa(const double nb, size_t precision)
{
	char					*ret;
	size_t					char_count;
	double					reduced_nb;
	size_t					precomma_cursor;
	unsigned long long int	ullint_nb;

	char_count = ft_precision_charcount(nb, precision);
	ret = malloc((char_count + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	precomma_cursor = char_count - precision - 1;
	reduced_nb = 0;
	ullint_nb = ft_precomma(ret, nb, &reduced_nb, &char_count);
	while (ullint_nb > 0)
	{
		ret[--precomma_cursor] = (ullint_nb % 10) + '0';
		ullint_nb /= 10;
	}
	if (precision > 0)
		ret[char_count - precision] = '.';
	ft_aftercomma(ret, reduced_nb, char_count, precision);
	return (ret);
}
