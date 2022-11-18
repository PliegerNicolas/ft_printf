/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sntoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:21:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 14:06:12 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
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
