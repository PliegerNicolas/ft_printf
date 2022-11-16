/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 16:27:17 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	*ft_memcpy_padded(void *dest, const void *src, size_t start, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i + start < n)
	{
		*(unsigned char *)(dest + i + start) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new_ptr;
	size_t	cur_size;

	if (!ptr)
		return (malloc(size));
	cur_size = sizeof(ptr);
	if (size <= cur_size)
		return (ptr);
	new_ptr = malloc(size);
	ft_bzero(new_ptr, size);
	ft_memcpy(new_ptr, ptr, cur_size);
	free(ptr);
	return (new_ptr);
}


void	*ft_realloc_mempadded(void *ptr, size_t size)
{
	char	*new_ptr;
	size_t	cur_size;

	if (!ptr)
		return (malloc(size));
	cur_size = sizeof(ptr);
	if (size <= cur_size)
		return (ptr);
	new_ptr = malloc(size);
	ft_bzero(new_ptr, size);
	ft_memcpy_padded(new_ptr, ptr, cur_size + 1, size);
	free(ptr);
	return (new_ptr);
}
