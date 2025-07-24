/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:36:54 by suju              #+#    #+#             */
/*   Updated: 2025/06/15 21:18:42 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_handler(char format, va_list ap)
{
	int	res;

	res = 0;
	if (format == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_print_unsigned_nbr(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	res = ft_print_char('%');
	if (res == -1)
		return (-1);
	res = ft_print_char(format);
	if (res == -1)
		return (-1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		total_len;
	int		len;

	va_start(ap, str);
	total_len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len = ft_format_handler(*str, ap);
			if (len == -1)
				return (-1);
			total_len += len;
		}
		else if (write(1, str, 1) == -1)
			return (-1);
		else
			total_len++;
		str++;
	}
	va_end(ap);
	return (total_len);
}
