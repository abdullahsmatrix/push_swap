/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:06:34 by amamun            #+#    #+#             */
/*   Updated: 2025/12/31 23:02:48 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_current_position(t_stack_node *stack)
{
    int i;
    int median;
    
    i = 0;
    if (NULL == stack)
        return ;
    median = stack_len(stack) / 2;
    while(stack)
    {
        stack->current_position == i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++; 
    }
}

static void set_target_node_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current_a;
    t_stack_node    *target_node;
    long            best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        current_a = a;
        while (current_a)
        {
            if (current_b->value < a->value
                && current_b->value > best_match_index)
            {
                best_match_index = current_b->value;
                target_node = current_b;   
            }
            current_b = current_b->next;    
        }
        if (LONG_MAX == best_match_index)
            a->target_node = find_largest(b);
        else
            a->target_node = target_node;
        a = a->next;
    }
}

static void cost_analysis(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;
    
    len_a = stack_len(a);
    len_b = stack_len(b);
    while (a)
    {
        a->push_cost = a->current_position;
        if (!(a->above_median))
            a->push_cost =len_a - (a->current_position);
        if (a->target_node->above_median)
            a->push_cost += a->target_node->current_position;
        else
            a->push_cost += len_b - (a->target_node->current_position);
    }
}

void set_cheapest(t_stack_node *stack)
{
    long cheapest_value;
    t_stack_node *cheapest_node;
    if(!stack)
        return ;
    cheapest_value = LONG_MAX;
    while(stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack -> push_cost;
            cheapest_node = stack;
        }
        stack = stack -> next;
    }
    cheapest_node->cheapest = true;
}
void init_nodes(t_stack_node *a, t_stack_node *b)
{
    set_current_position(a);
    set_current_position(b);
    set_target_node_a(a, b);
    cost_analysis(a, b);
    set_cheapest(b);
}