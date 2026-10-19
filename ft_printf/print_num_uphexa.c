/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numUphexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:53:31 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/13 11:53:41 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num_uphexa(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += print_num_uphexa(n / 16);
	}
	if ((n % 16) < 10)
		num = n % 16 + '0';
	else
		num = n % 16 - 10 + 'A';
	write(1, &num, 1);
	return (count + 1);
}
