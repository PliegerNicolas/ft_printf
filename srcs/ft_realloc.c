/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/24 15:08:51 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	*ft_memcpy_padded(char *dest, char *src, size_t n, size_t start)
{
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (start < n)
		*(unsigned char *)(dest + start++) = *(src + i++);
	return (dest);
}

static void	ft_fillpadding(char *str, char padding_char, size_t n)
{
	while (n--)
		if (str[n] == '\0')
			str[n] = padding_char;
}

void	*ft_realloc_padding(t_flags *flags_list, char padding_char)
{
	char	*new_str;

	new_str = malloc((flags_list->width) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, flags_list->width);
	if (flags_list->dash)
		ft_memcpy(new_str, flags_list->str, flags_list->width);
	else
		ft_memcpy_padded(new_str, flags_list->str, flags_list->width,
			flags_list->width - ft_strlen(flags_list->str));
	ft_fillpadding(new_str, padding_char, flags_list->width);
	free(flags_list->str);
	return (new_str);
	return ((void *)flags_list->str);
}
