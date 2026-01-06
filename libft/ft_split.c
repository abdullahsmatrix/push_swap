/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:03:01 by amamun            #+#    #+#             */
/*   Updated: 2026/01/06 21:10:11 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while (s[*cursor + len] && s[*cursor + len] != c)
		++len;
	next_word = malloc(len + 1);
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	i = 0;
	cursor = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!result_array)
		return (NULL);
	while (i < words_count)
	{
		result_array[i++] = get_next_word(s, c, &cursor);
	}
	result_array[i] = NULL;
	return (result_array);
}
