/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:41:40 by suju              #+#    #+#             */
/*   Updated: 2025/06/15 16:24:01 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	len;
	int	res;

	len = 0;
	if (ptr == NULL)
	{
		res = ft_print_str("(nil)");
		if (res == -1)
			return (-1);
		return (res);
	}
	res = ft_print_str("0x");
	if (res == -1)
		return (-1);
	len += res;
	res = ft_print_hex((unsigned long) ptr, 'x');
	if (res == -1)
		return (-1);
	len += res;
	return (len);
}
