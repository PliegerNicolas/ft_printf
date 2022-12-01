/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:16:36 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 16:54:50 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_addprefix(t_flags *flags, const char *prefix)
{
	char		*new_str;
	size_t		prefix_len;
	size_t		i;

	prefix_len = ft_strlen(prefix);
	new_str = malloc ((flags->strlen + prefix_len + 1) * sizeof(char));
	if (!new_str)
		return ;
	flags->strlen += prefix_len;
	i = 0;
	while (i < prefix_len)
	{
		new_str[i] = prefix[i];
		i++;
	}
	i = 0;
	while (flags->str[i])
		new_str[prefix_len++] = flags->str[i++];
	new_str[prefix_len] = '\0';
	free(flags->str);
	flags->str = new_str;
}
