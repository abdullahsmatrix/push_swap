/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:21:03 by amamun            #+#    #+#             */
/*   Updated: 2026/01/06 21:23:59 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*largest_node;

	largest_node = find_largest_node(*a);
	if (*a == largest_node)
		ra(a, false);
	else if ((*a)->next == largest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
