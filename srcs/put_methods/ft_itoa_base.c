/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:43:14 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 16:03:56 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static char	*ft_malloc(int *nb, unsigned int *nb_ui)
{
	char	*ret;

	ret = malloc(40 * sizeof(char));
	if (!ret)
		return (NULL);
	if (*nb < 0)
		*nb_ui = (*nb) * -1;
	else
		*nb_ui = *nb;
	return (ret);
}

static char	*ft_mallocl(void)
{
	char	*ret;

	ret = malloc(40 * sizeof(char));
	if (!ret)
		return (NULL);
	return (ret);
}

char	*ft_itoa_base(int nb, const char *base)
{
	char			*ret;
	size_t			i;
	size_t			base_divider;
	unsigned int	nb_ui;

	ret = ft_malloc(&nb, &nb_ui);
	if (!ret)
		return (NULL);
	i = 0;
	if (nb_ui == 0)
		ret[i++] = '0';
	base_divider = ft_strlen(base);
	while (nb_ui > 0)
	{
		ret[i++] = base[nb_ui % base_divider];
		nb_ui /= base_divider;
	}
	if (nb < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}

char	*ft_ltoa_base(unsigned long nb, const char *base)
{
	char		*ret;
	size_t		i;
	size_t		base_divider;

	ret = ft_mallocl();
	if (!ret)
		return (NULL);
	i = 0;
	if (nb == 0)
		ret[i++] = '0';
	base_divider = ft_strlen(base);
	while (nb > 0)
	{
		ret[i++] = base[nb % base_divider];
		nb /= base_divider;
	}
	ret[i] = '\0';
	return (ft_strrev(ret));
}
