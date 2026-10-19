/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:26:58 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/10 17:36:38 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_hexa(unsigned long n)
{
	char	num;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += print_hexa(n / 16);
	}
	if ((n % 16) < 10)
		num = n % 16 + '0';
	else
		num = n % 16 - 10 + 'a';
	write(1, &num, 1);
	return (count + 1);
}

int	print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += print_hexa((unsigned long)ptr);
	return (count);
}
