/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:09:39 by amamun            #+#    #+#             */
/*   Updated: 2026/01/04 20:22:29 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlcpy(char *dest, char const *src, size_t n)
{
	size_t i;

	if (dest == NULL && n == 0)
		return (ft_strlen(src));
	i = 0;
	if (n == 0)
	{
		return (ft_strlen(src));
	}
	while (*(src + i) && i < n - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}