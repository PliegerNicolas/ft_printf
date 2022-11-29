/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 17:27:35 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	*ft_memcpy_padded(char *dest, char *src, t_flags *flags)
{
	size_t		i;
	size_t		start;


	if (!dest && !src)
		return (NULL);
	// a voir si numeric se fait truncat ou skip.
	i = 0;
	if (src[0] == '-' && !(flags->type == 's') && flags->dot && flags->precision > flags->strlen)
	{
		dest[0] = '-';
		src++;
		flags->strlen--;
		flags->max_width++;
	}
	start = flags->max_width - flags->strlen;
	while (start < flags->max_width)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
	return (dest);
}

void	*ft_memsafecpy(void *dest, const void *src, size_t max_width)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < max_width)
	{
		if (*(unsigned char *)(src + i))
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		else
			break ;
		i++;
	}
	return (dest);
}
