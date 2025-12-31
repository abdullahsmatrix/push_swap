/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:03:01 by amamun            #+#    #+#             */
/*   Updated: 2025/12/18 21:14:41 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
static int word_count(char const *s, char c)
{
    int count;
    
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

static int safe_malloc(char **words_v, int position, size_t buffer)
{
    int i;
    
    i = 0;
    words_v[position] = malloc(buffer);
    if (NULL == words_v[position])
    {
        while (i < position)
        {
            free(words_v[i]);
            i++;
        }
        free(words_v);
        return (1);
    }
    return (0);
}

static void fill_word(char **words_v, const char *s, char c)
{
    int i;
    size_t len;
    
    i = 0;
    while (*s)
    {
        len = 0;
        while (*s && *s == c)
            s++;
        while (*s && *s != c)
        {
            s++;
            len++;
        }
        if (len > 0)
        {
            if (safe_malloc(words_v, i, len + 1))
                return ;
            ft_strlcpy(words_v[i], s - len, len + 1);
            i++;
        }
    }
}

char **ft_split(char const *s, char c)
{
    int words;
    int i;
    char **words_v;
    
    i = 0;
    words = word_count(s, c);
    words_v = (char **) malloc(sizeof(char *) * (words + 1));
    if (NULL == words_v)
        return (NULL);
    words_v[words] = NULL;
    fill_word(words_v, s, c);
    return words_v;
}