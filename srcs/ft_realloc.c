/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/30 15:35:50 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	*ft_memcpy_padded(char *dest, char *src, t_flags *flags)
{
	size_t		i;
	size_t		start;

	if (!dest && !src)
		return (NULL);
	i = 0;
	start = flags->max_width - flags->strlen;
	if (src[0] == '-' && !(flags->type == 's') && flags->dot
		&& flags->precision >= flags->strlen)
	{
		dest[0] = '-';
		src++;
		start++;
	}
	while (start < flags->max_width)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
	while (start < flags->extra_right_padding + flags->max_width)
		*(unsigned char *)(dest + start++) = ' ';
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
			*(unsigned char *)(dest + i) = ' ';
		else
			break ;
		i++;
	}
	return (dest);
}
