/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsignednum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:00:10 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/10 12:00:45 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsignednum(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += print_unsignednum(n / 10);
	}
	num = n % 10 + '0';
	write(1, &num, 1);
	return (count + 1);
}
