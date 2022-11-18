/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:51:37 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 10:22:27 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

long long int	ft_power(long long int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 || (power == 0 && nb == 0))
		return (1);
	return (nb * ft_power(nb, power -1));
}
