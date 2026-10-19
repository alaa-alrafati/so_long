/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:56:00 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/15 13:04:45 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_num(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsignednum(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += print_num_lhexa(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count += print_num_uphexa(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			count += print_format(ap, format[i]);
			i++;
		}
		else
			count += print_char(format[i++]);
	}
	va_end(ap);
	return (count);
}
