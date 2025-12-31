/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:53:32 by amamun            #+#    #+#             */
/*   Updated: 2025/12/31 22:58:39 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;
    cheapest_node = get_cheapest(*a)
}

void sort_algo(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *smallest;
    int len_a;
    
    len_a = stack_len(*a);
    if (len_a-- > 3)
        pb(a, b, false);
    if (len_a-- > 3)
        pb(a, b, false);
    while(len_a-- > 3)
    {
        init_nodes(*a, *b);
        move_a_to_b(b, a);
    }
}