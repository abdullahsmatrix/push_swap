#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/// @brief find largest value of the stack
/// @param stack 
/// @return 

t_stack_node *find_largest(t_stack_node *stack)
{
    int largest;
    t_stack_node *largest_node;

    if(NULL == stack)
        return (NULL);
    
    largest = INT_MIN;
    while(stack)
    {
        if(stack->value > largest)
        {
            largest = stack -> value;
            largest_node = stack;
        }
        stack = stack -> next;
    }
    return (largest_node);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////                                        
///find largest->send largest to last-> check if first two nodes sorted->if sorted, leave. else, swapon///
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void tiny_sort(t_stack_node **stack)
{
    t_stack_node *largest_node;
    largest_node = find_largest(*stack);
    if (*stack == largest_node)
        ra(stack, false);
    else if((*stack)->next == largest_node)
        rra(stack, false);
    if((*stack)->value > (*stack)->next->value)
        sa(stack, false);
}