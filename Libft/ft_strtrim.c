/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:20:34 by suju              #+#    #+#             */
/*   Updated: 2025/04/12 16:53:48 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char target, char const *set)
{
	while (*set != '\0')
	{
		if (target == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_idx;
	size_t	end_idx;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start_idx = 0;
	while (s1[start_idx] != '\0' && is_in_set(s1[start_idx], set))
		start_idx++;
	end_idx = ft_strlen(s1);
	if (end_idx > 0)
		end_idx--;
	while (end_idx > start_idx && is_in_set(s1[end_idx], set))
		end_idx--;
	return (ft_substr(s1, start_idx, end_idx - start_idx + 1));
}
