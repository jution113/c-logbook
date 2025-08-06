/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:34:02 by suju              #+#    #+#             */
/*   Updated: 2025/04/13 14:42:32 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	s_len;
	size_t	idx;

	if (s == NULL || f == NULL)
		return ;
	s_len = ft_strlen(s);
	idx = 0;
	while (idx < s_len)
	{
		f(idx, &s[idx]);
		idx++;
	}
}
