/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:47:46 by suju              #+#    #+#             */
/*   Updated: 2025/06/15 21:06:50 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_recur(long nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr >= 10)
	{
		len = ft_print_nbr_recur(nbr / 10);
		if (len == -1)
			return (-1);
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_nbr(long nbr)
{
	int	total_len;
	int	len;

	total_len = 0;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nbr *= -1;
		total_len++;
	}
	len = ft_print_nbr_recur(nbr);
	if (len == -1)
		return (-1);
	total_len += len;
	return (total_len);
}
