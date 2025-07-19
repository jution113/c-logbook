/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:47 by suju              #+#    #+#             */
/*   Updated: 2025/04/21 21:39:37 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_num_len(long long l_n)
{
	size_t	len;

	len = 0;
	if (l_n < 0)
	{
		len++;
		l_n *= -1;
	}
	while (l_n >= 10)
	{
		l_n /= 10;
		len++;
	}
	len++;
	return (len);
}

void	recur_itoa(long long l_n, char *res, size_t *idx)
{
	if (l_n >= 10)
		recur_itoa(l_n / 10, res, idx);
	res[(*idx)++] = l_n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		num_len;
	size_t		idx;
	long long	l_n;

	l_n = n;
	num_len = get_num_len(l_n);
	res = (char *)malloc(num_len + 1);
	if (res == NULL)
		return (NULL);
	idx = 0;
	if (l_n < 0)
	{
		l_n *= -1;
		res[idx++] = '-';
	}
	recur_itoa(l_n, res, &idx);
	res[idx] = '\0';
	return (res);
}
