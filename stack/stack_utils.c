/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:22:13 by amamun            #+#    #+#             */
/*   Updated: 2025/12/30 21:30:37 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/// @brief: Sorted or ot check
/// @param: stack
/// @return: true/false
bool stack_sorted(t_stack_node *stack)
{
    if (NULL == stack)
        return (1);
    while(stack->next)
    {   
        if(stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

t_stack_node *find_last_node(t_stack_node *current)
{
    if (NULL == current)
        return (NULL);
    while (current->next)
        current = current->next;
    return (current);
}

int stack_len(t_stack_node *stack)
{
    int count;
    if (NULL == stack)
        return (0);
    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}