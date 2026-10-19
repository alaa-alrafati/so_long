/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numLhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:49:11 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/13 11:49:28 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num_lhexa(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += print_num_lhexa(n / 16);
	}
	if ((n % 16) < 10)
		num = n % 16 + '0';
	else
		num = n % 16 - 10 + 'a';
	write(1, &num, 1);
	return (count + 1);
}
