/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issignedzero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:20:29 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 16:26:13 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ispositivezero(double nb)
{
	return (1 / nb == 1 / 0.0);
}

int	ft_isnegativezero(double nb)
{
	return (1 / nb == 1 / -0.0);
}
