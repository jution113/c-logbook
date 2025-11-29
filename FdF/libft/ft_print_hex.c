/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:52:53 by suju              #+#    #+#             */
/*   Updated: 2025/06/08 17:19:08 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_recur(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len = ft_print_hex_recur(nbr / 16, base);
		if (len == -1)
			return (-1);
	}
	if (write(1, &base[nbr % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned long nbr, char format)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (format == 'x')
		base = "0123456789abcdef";
	return (ft_print_hex_recur(nbr, base));
}
