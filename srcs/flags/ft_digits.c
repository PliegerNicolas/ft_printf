/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:08:41 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 18:04:12 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_count_width(char *s, size_t integer_digits_size)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (integer_digits_size > i)
		return (integer_digits_size);
	return (i);
}

void	ft_digits_setter(const char *s, t_flags *flags_list, int *i)
{
	if (flags_list->asterisk)
		return ;
	flags_list->digit = TRUE;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		flags_list->precision *= 10;
		flags_list->precision += s[(*i)++] - '0';
	}
	if (s[*i] && s[*i] == '.')
	{
		flags_list->dot = TRUE;
		flags_list->precision_dot = 0;
		(*i)++;
	}
	while (s[*i] && ft_isdigit(s[*i]))
	{
		flags_list->precision_dot *= 10;
		flags_list->precision_dot += s[(*i)++] - '0';
	}
	flags_list->width = flags_list->precision + flags_list->precision_dot + 1;
}

static void	ft_digits_convertor_float(t_flags *flags_list)
{
	size_t	integer_digits_size;
	size_t	fractional_digits_size;

	integer_digits_size = flags_list->precision;
	if (flags_list->dot)
		fractional_digits_size = flags_list->precision_dot;
	else
	{
		flags_list->precision_dot = 0;
		fractional_digits_size = flags_list->precision_dot;
	}
	flags_list->width = ft_count_width(flags_list->str, integer_digits_size)
		+ fractional_digits_size;
	if (flags_list->dot)
		flags_list->width++;
	if (flags_list->type == '\0')
		flags_list->width--;
	flags_list->str = ft_realloc_float(flags_list);
}

static void	ft_digits_convertor_string(t_flags *flags_list)
{
	size_t		min_size;
	size_t		max_size;
	size_t		strlen;

	if (flags_list->dot)
	{
		min_size = flags_list->precision;
		max_size = flags_list->precision_dot;
		strlen = ft_strlen(flags_list->str);
		if (max_size > strlen && !min_size)
			max_size = strlen;
		if (min_size > max_size)
			min_size = max_size;
		//min_size = 0;
		//if (flags_list->precision)
		//	min_size = flags_list->precision;
		//max_size = flags_list->precision_dot;
		//if (max_size < min_size)
		//	max_size = min_size;
		//if (max_size > ft_strlen(flags_list->str))
		//	max_size = ft_strlen(flags_list->str);
		//if (!flags_list->precision && !flags_list->precision_dot)
		//	max_size = ft_strlen(flags_list->str);
		//min_size = flags_list->precision;
		//max_size = ft_strlen(flags_list->str);
		//max_size = flags_list->precision_dot;
		//if (max_size <= min_size)
		//	max_size = min_size;
	}
	else
	{
		min_size = 0;
		max_size = ft_strlen(flags_list->str);
		if (flags_list->precision > max_size)
			max_size = flags_list->precision;
	}
	flags_list->str = ft_realloc_str(flags_list, min_size, max_size);
}

void	ft_digits_convertor(t_flags *flags_list)
{
	if (flags_list->digit == FALSE && flags_list->asterisk == FALSE)
		return ;
	if (flags_list->type == 's' || flags_list->type == 'p')
		ft_digits_convertor_string(flags_list);
	else
		ft_digits_convertor_float(flags_list);
}
