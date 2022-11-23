/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 14:49:17 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
static void	ft_chrcpy_pad(char *dest, char *src, size_t start, size_t size)
{
	size_t		i;

	if (!dest && !src)
		return ;
	i = 0;
	while (i + start < size)
	{
		dest[i + start] = src[i];
		i++;
	}
}

void	*ft_realloc_str(char *str, size_t current_size, size_t size)
{
	char	*new_str;

	if (!str)
		return ((void *)malloc(size * sizeof(char)));
	if (size <= current_size)
		return ((void *)str);
	new_str = malloc(size + 1);
	ft_bzero((void *)new_str, size + 1);
	ft_memcpy((void *)new_str, (void *)str, current_size);
	free(str);
	return ((void *)new_str);
}

void	*ft_realloc_paddedstr(char *str, size_t current_size, size_t size)
{
	char	*new_str;

	if (!str)
		return ((void *)malloc(size * sizeof(char)));
	if (size <= current_size)
		return (str);
	new_str = malloc(size + 1);
	ft_bzero((void *)new_str, size + 1);
	ft_chrcpy_pad(new_str, str, size - current_size, size);
	free(str);
	return ((void *)new_str);
}
*/

static void	ft_fillpadding(char *s, t_flags *flags_list)
{
	size_t		i;
	char		paddingchar;

	i = 0;
	paddingchar = ft_select_paddingchar(flags_list);
	while (i < flags_list->width)
	{
		if (s[i] == '\0')
			s[i] = paddingchar;
		i++;
	}
}

static void	*ft_memcpy_padded(void *dest, const void *src, size_t n,
						size_t start)
{
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (start < n)
		*(unsigned char *)(dest + start++) = *(unsigned char *)(src + i++);
	return (dest);
}

void	*ft_realloc_str(t_flags *flags_list, size_t min_size, size_t max_size)
{
	char	*new_str;

	if (!flags_list->str)
		return (flags_list->str);
	if (flags_list->dot)
	{
		if (max_size < min_size)
			flags_list->width = min_size;
		else
			flags_list->width = max_size;
	}
	new_str = malloc((flags_list->width + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_bzero((void *)new_str, flags_list->width + 1);
	if (flags_list->dash)
		ft_memcpy((void *)new_str, (void *)flags_list->str,
			flags_list->width + 1);
	else
		ft_memcpy_padded((void *)new_str, (void *)flags_list->str,
			flags_list->width,
			flags_list->width - ft_strlen(flags_list->str));
	ft_fillpadding(new_str, flags_list);
	free(flags_list->str);
	return ((void *)new_str);
}

void	*ft_realloc_float(t_flags *flags_list)
{
	char	*new_str;

	if (!flags_list->str)
		return (flags_list->str);
	new_str = malloc((flags_list->width + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_bzero((void *)new_str, flags_list->width + 1);
	if (flags_list->dash)
		ft_memcpy((void *)new_str, (void *)flags_list->str,
			flags_list->width + 1);
	else
		ft_memcpy_padded((void *)new_str, (void *)flags_list->str,
			flags_list->width,
			flags_list->width - ft_strlen(flags_list->str));
	ft_fillpadding(new_str, flags_list);
	free(flags_list->str);
	return ((void *)new_str);
}
