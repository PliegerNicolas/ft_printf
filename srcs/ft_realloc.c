/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 13:09:26 by nplieger         ###   ########.fr       */
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
	if (src[0] == '-' && ft_isnumeric(flags->type)
		&& (flags->dot || (!flags->dot && flags->zero)))
	{
		dest[0] = '-';
		src++;
		start++;
	}
	while (start < flags->max_width)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
	while (start < flags->extra_rightpadd + flags->max_width)
		*(unsigned char *)(dest + start++) = ' ';
	return (dest);
}

void	*ft_memsafecpy(void *dest, const void *src, t_flags *flags)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < flags->max_width)
	{
		if (*(unsigned char *)(src + i))
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		else
			break ;
		i++;
	}
	while (flags->extra_rightpadd--)
		*(unsigned char *)(dest + i++) = ' ';
	return (dest);
}
