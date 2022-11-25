/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/25 12:27:19 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_realloc_int(t_flags *flags_list, size_t strlen)
{
	if (flags_list->dot)
	{
		if (flags_list->dot && flags_list->precision
			&& flags_list->precision > strlen)
		{
			flags_list->zero = TRUE;
			flags_list->dash = FALSE;
			flags_list->width = flags_list->precision;
			flags_list->str = ft_realloc_padding(flags_list,
					ft_select_paddingchar(flags_list));
		}
		else
		{
			flags_list->dash = TRUE;
			flags_list->zero = FALSE;
			flags_list->width = strlen;
			flags_list->precision = strlen;
		}
	}
}

static void	*ft_memcpy_padded(char *dest, char *src, size_t n, size_t start)
{
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (start <= n)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
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

	new_str = malloc((flags_list->width + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, flags_list->width + 1);
	if (flags_list->dash)
		ft_memcpy(new_str, flags_list->str, flags_list->width);
	else
		ft_memcpy_padded(new_str, flags_list->str, flags_list->width,
			flags_list->width - ft_strlen(flags_list->str));
	ft_fillpadding(new_str, padding_char, flags_list->width);
	free(flags_list->str);
	return (new_str);
}
