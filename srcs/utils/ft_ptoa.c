/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:52 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/21 17:21:00 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_ptoa(void *ptr)
{
	char		*ret;
	char		*temp;

	temp = ft_ltoa_base((unsigned long long int)ptr, "0123456789abcdef");
	ret = ft_strjoin("0x", temp);
	free(temp);
	return (ret);
}
