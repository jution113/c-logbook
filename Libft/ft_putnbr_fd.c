/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:22:18 by suju              #+#    #+#             */
/*   Updated: 2025/04/13 15:44:10 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_recur(long long l_n, int fd)
{
	if (l_n >= 10)
		putnbr_recur(l_n / 10, fd);
	ft_putchar_fd(l_n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	l_n;

	l_n = n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n *= -1;
	}
	putnbr_recur(l_n, fd);
}
