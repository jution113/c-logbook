/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:50:39 by suju              #+#    #+#             */
/*   Updated: 2025/06/15 08:49:59 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_nbr_recur(unsigned int nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr >= 10)
	{
		len = ft_print_unsigned_nbr_recur(nbr / 10);
		if (len == -1)
			return (-1);
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_unsigned_nbr(unsigned int nbr)
{
	return (ft_print_unsigned_nbr_recur(nbr));
}
