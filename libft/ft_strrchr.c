/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:21:19 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/12 14:32:29 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		revi;
	char		*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	revi = ft_strlen(str);
	if (!c)
		return (str + revi);
	while (revi--)
		if (str[revi] == (char)c)
			return (str + revi);
	return (NULL);
}
