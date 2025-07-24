/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:56:06 by suju              #+#    #+#             */
/*   Updated: 2025/04/21 21:34:24 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	cnt;
	size_t	is_in_word;

	cnt = 0;
	is_in_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			is_in_word = 0;
		else if (is_in_word == 0)
		{
			is_in_word = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

char	*malloc_word(const char *s, char c)
{
	size_t	len;
	size_t	idx;
	char	*word;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		word[idx] = s[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

void	free_all(char **word_arr, int arr_idx)
{
	while (--arr_idx >= 0)
		free(word_arr[arr_idx]);
	free(word_arr);
}

void	fill_word_arr(char **word_arr, char const *s, char c)
{
	size_t	arr_idx;
	char	*word;

	arr_idx = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			word = malloc_word(s, c);
			if (word == NULL)
			{
				free_all(word_arr, arr_idx);
				return ;
			}
			word_arr[arr_idx++] = word;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	word_arr[arr_idx] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	word_cnt;
	char	**word_arr;

	if (s == NULL)
		return (NULL);
	word_cnt = count_word(s, c);
	word_arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (word_arr == NULL)
		return (NULL);
	fill_word_arr(word_arr, s, c);
	return (word_arr);
}
