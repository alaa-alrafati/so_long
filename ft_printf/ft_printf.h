/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:57:48 by aalrofat          #+#    #+#             */
/*   Updated: 2025/09/13 11:53:51 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_string(char *s);
int	print_num(int n);
int	print_unsignednum(unsigned int n);
int	print_pointer(void *ptr);
int	print_num_lhexa(unsigned int n);
int	print_num_uphexa(unsigned int n);
#endif
