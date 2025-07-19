/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:28:10 by suju              #+#    #+#             */
/*   Updated: 2025/04/13 14:33:04 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	idx;
	char	*res;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	res = (char *)malloc(s_len + 1);
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < s_len)
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
