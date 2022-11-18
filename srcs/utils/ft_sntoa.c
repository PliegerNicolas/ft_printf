/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sntoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:21:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 15:50:08 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static double ft_shiftcomma(const double *nb, int *comma_shift)
{
	double	d_nb;

	if (*nb == 0)
		return (*nb);
	d_nb = *nb;
	while (d_nb >= 10 || d_nb <= -10)
	{
		(*comma_shift)--;
		d_nb /= 10;
	}
	while (d_nb < 1 && d_nb > -1)
	{
		(*comma_shift)++;
		d_nb *= 10;
	}
	return (d_nb);
}

char	*ft_sntoa(const double nb, const size_t precision, const t_bool caps)
{
	char	*ret;
	double	d_nb;
	int		comma_shift;
	size_t	size;

	comma_shift = 0;
	d_nb = ft_shiftcomma(&nb, &comma_shift);
	size = ft_precision_charcount(d_nb, precision) + ft_precision_charcount(comma_shift, 0) + 1;
	if ((comma_shift / 10) < 10 && (comma_shift / 10) > -10)
		size++;
	ret = malloc((size + 1) * sizeof(char));
	(void)d_nb;
	(void)caps;
	(void)precision;
	return (ret);
}

/*
int	main(void)
{
	char	*s;
	double	nb;
	size_t	precision;
	t_bool	caps;

	nb = 1.123;
	precision = 0;
	caps = true;
	s = ft_sntoa(nb, precision, caps);
	printf("%s\n", s);
	printf("%.0e\n", nb);
	free(s);
	return (0);
}
*/

/*
static void	ft_push_comma(double *nb, int *comma_placement)
{
	// A corriger et continuer les fonctions de ce fichier.
	if ((int)(*nb) == 0 && (int)(*nb * 10) == 0)
		return ;
	while ((int)(*nb) <= 0 || (int)(*nb) >= 10)
	{
		if ((int)(*nb) >= 10)
		{
			*nb /= 10;
			(*comma_placement)--;
		}
		else if ((int)(*nb) <= 0)
		{
			*nb *= 10;
			(*comma_placement)++;
		}
	}
}

static char	*ft_addsubstr_scientific(int comma_placement, const t_bool caps)
{
	char		*substr_sn;
	size_t		size;

	size = ft_charcount(comma_placement) + 2;
	substr_sn = (char *)malloc(size * sizeof(char));
	if (!substr_sn)
		return (NULL);
	substr_sn[--size] = '\0';
	substr_sn[0] = 'e';
	if (caps)
		substr_sn[0] -= 32;
	if (comma_placement >= 0)
		substr_sn[1] = '+';
	else
	{
		substr_sn[1] = '-';
		comma_placement *= -1;
	}
	while (comma_placement < 0 || comma_placement >= 1)
	{
		substr_sn[--size] = (comma_placement % 10) + '0';
		comma_placement /= 10;
	}
	return (substr_sn);
}


char	*ft_sntoa(double nb, const size_t precision, const t_bool caps)
{
	char	*nb_str;
	char	*substr_sn;
	int		comma_placement;

	comma_placement = 0;
	ft_push_comma(&nb, &comma_placement);
	nb_str = ft_dtoa(nb, precision);
	if (!nb_str)
		return (NULL);
	substr_sn = ft_addsubstr_scientific(comma_placement, caps);
	if (!substr_sn)
	(void)sn_substr;
		return (NULL);
	return (nb_str);
}

int	main(void)
{
	double	nb;
	size_t	precision;

	precision = 5;
	nb = 1125123512351235230.2340;
	printf("%s\n", ft_sntoa(nb, precision, true));
	nb = 0.0;
	printf("%s\n", ft_sntoa(nb, precision, false));
	return (0);
}
*/
