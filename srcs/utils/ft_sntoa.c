/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sntoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:21:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/21 10:50:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static double	ft_commashift(double *nb_cpy, int *commashift)
{
	int		commashift_cpy;
	size_t	commashift_len;

	while (*nb_cpy > 10 || *nb_cpy <= -10)
	{
		(*commashift)++;
		*nb_cpy /= 10;
	}
	while (*nb_cpy < 1 && *nb_cpy > -1 && *nb_cpy != 0)
	{
		(*commashift)--;
		*nb_cpy *= 10;
	}
	commashift_len = 0;
	commashift_cpy = *commashift;
	while (commashift_cpy >= 1 || commashift_cpy <= -1)
	{
		commashift_cpy /= 10;
		commashift_len++;
	}
	if (commashift_len < 2)
		commashift_len = 2;
	return (commashift_len);
}

static void	ft_handle_substr(char *ret, int *commashift, size_t *char_count,
						size_t *substr_len)
{
	ret[(*char_count)--] = '+';
	if (*commashift < 0)
	{
		ret[(*char_count) + 1] = '-';
		*commashift = -(*commashift);
	}
	ret[(*char_count)--] = 'e';
	while (*substr_len)
	{
		ret[(*char_count) + 2 + (*substr_len)--] = (*commashift) % 10 + '0';
		*commashift /= 10;
	}
}

static void	ft_handle_precision(char *ret, double *nb, const size_t precision,
							size_t *char_count)
{
	size_t	precision_cpy;

	precision_cpy = precision;
	if (precision_cpy)
	{
		*nb *= ft_power(10, precision_cpy);
		while (precision_cpy--)
		{
			ret[(*char_count)--] = ft_dmod(*nb, 10) + '0';
			*nb /= 10;
		}
		ret[(*char_count)--] = '.';
	}
}

char	*ft_sntoa(const double nb, const size_t precision, const t_bool caps)
{
	char	*ret;
	double	nb_cpy;
	int		commashift;
	size_t	char_count;
	size_t	substr_len;

	commashift = 0;
	nb_cpy = nb;
	substr_len = ft_commashift(&nb_cpy, &commashift);
	char_count = ft_precision_charcount(nb_cpy, precision) + 2;
	ret = malloc((char_count + substr_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[char_count-- + substr_len] = '\0';
	ft_handle_substr(ret, &commashift, &char_count, &substr_len);
	if (caps)
		ret[char_count + 1] -= 32;
	while (substr_len)
	{
		ret[char_count + 2 + substr_len--] = commashift % 10 + '0';
		commashift /= 10;
	}
	ft_handle_precision(ret, &nb_cpy, precision, &char_count);
	ret[char_count--] = ft_dmod(nb_cpy, 10) + '0';
	if (nb_cpy < 0 || ft_isnegativezero(nb_cpy))
		ret[char_count] = '-';
	return (ret);
}

int	main(void)
{
	char	*ret;
	double	nb;
	t_bool	caps;
	size_t	precision;

	nb = 0.00123;
	precision = 1;
	caps = false;
	ret = ft_sntoa(nb, precision, caps);
	printf("%s\n", ret);
	if (caps)
		printf("%.1E", nb);
	else
		printf("%.1e", nb);
	free(ret);
	return (0);
}
