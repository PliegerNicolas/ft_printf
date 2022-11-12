/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:01 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/10 10:36:03 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			ret;

	while (n--)
	{
		ret = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (ret)
			return (ret);
	}
	return (0);
}
