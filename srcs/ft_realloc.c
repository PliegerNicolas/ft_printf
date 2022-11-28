/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 12:48:27 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	*ft_memcpy_padded(char *dest, t_flags *flags_list, size_t n, size_t start)
{
	size_t		i;
	char		*src;

	src = flags_list->str;
	if (!dest && !src)
		return (NULL);
	if (src[0] == '-' && flags_list->precision && flags_list->dot && !flags_list->digits)
	{
		dest[0] = '-';
		src++;
		start = flags_list->width - ft_strlen(src);
		flags_list->width--;
	}
	i = 0;
	while (start <= n)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
	return (dest);
}

static void	*ft_memsafecpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(src + i))
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

static void	ft_fillpadding(char *str, char padding_char, size_t n, size_t extra_right_padding)
{
	if (extra_right_padding)
		while (extra_right_padding--)
			if (str[n + extra_right_padding] == '\0')
				str[n + extra_right_padding] = ' ';
	while (n--)
		if (str[n] == '\0')
			str[n] = padding_char;
}

void	*ft_realloc_padding(t_flags *flags_list, char padding_char)
{
	char	*new_str;

	new_str = malloc((flags_list->width + flags_list->extra_right_padding + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, flags_list->width + flags_list->extra_right_padding + 1);
	if (flags_list->dash)
		ft_memsafecpy(new_str, flags_list->str, flags_list->width);
	else
		ft_memcpy_padded(new_str, flags_list, flags_list->width,
			flags_list->width - ft_strlen(flags_list->str));
	ft_fillpadding(new_str, padding_char, flags_list->width, flags_list->extra_right_padding);
	free(flags_list->str);
	return (new_str);
}
