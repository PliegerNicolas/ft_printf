/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 11:53:33 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
