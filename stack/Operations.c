/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:00:24 by amamun            #+#    #+#             */
/*   Updated: 2025/12/30 21:23:27 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////////////////////////////////////////
////////////////////PUSH////////////////////////
///////////////////////////////////////////////

static void push(t_stack_node **src, t_stack_node **dest)
{
    
}

////////////////////////////////////////////////
////////////////////SWAP////////////////////////
////////////////////////////////////////////////

static void swap(t_stack_node **head)
{
    int len;

    len = stack_len(*head);
    if (NULL == *head || NULL == head || 1 == len)
        return ;
    *head = (*head) -> next;
    (*head) -> prev -> next = (*head) -> next;
    (*head) -> prev -> prev = (*head);
    if((*head) -> next)
        (*head) -> next -> prev = (*head) -> prev;
    (*head) -> next = (*head) -> prev;
    (*head) -> prev = NULL;
}

void sa(t_stack_node **a, bool checker)
{
    swap(a);
    if (!checker)
        write(1, "sa\n", 3);
}
void sb(t_stack_node **b, bool checker)
{
    swap(b);
    if (!checker)
        write(1, "sb\n", 3);
}

void ss(t_stack_node **a, t_stack_node **b, bool checker)
{
    swap(a);
    swap(b);
    if(!checker)
        write(1, "ss\n", 3);
}
////////////////////////////////////////////////
////////////////////ROTATE//////////////////////
////////////////////////////////////////////////

static void rotate(t_stack_node **stack)
{
    t_stack_node *last_node;
    int len;
    
    len = stack_len(*stack);
    if(NULL == stack || *stack == NULL || 1 == len)
        return ;
    last_node = find_last_node(*stack);
    (*stack) -> prev = last_node;
    last_node->next = (*stack);
    (*stack) = (*stack) -> next;
    (*stack) -> prev = NULL;
    last_node->next->next = NULL;
}

void ra(t_stack_node **a, bool checker)
{
    rotate(a);
    if(!checker)
        write(1, "ra\n", 3);
}

void rb(t_stack_node **b, bool checker)
{
    rotate(b);
    if(!checker)
        write(1, "rb\n", 3);
}

void rr(t_stack_node **a, t_stack_node **b, bool checker)
{
    rotate(a);
    rotate(b);
    if(!checker)
        write(1, "rr\n", 3);
}

////////////////////////////////////////////////
//////////////REVERSE ROTATE////////////////////
////////////////////////////////////////////////
static void reverse_rotate(t_stack_node **stack)
{
    int len;
    t_stack_node *last_node;
    
    if (NULL == stack || NULL == *stack)
        return ;
    len = stack_len(*stack);
    if (1 == len)
        return ;
    last_node = find_last_node(*stack);
    last_node -> prev -> next = NULL;
    last_node -> next = (*stack);
    (*stack) -> prev = last_node;
    last_node -> prev = NULL;
    (*stack) = last_node;
}

void rra(t_stack_node **a, bool checker)
{
    reverse_rotate(a);
    if (!checker)
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b, bool checker)
{
    reverse_rotate(b);
    if (!checker)
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (!checker)
        write(1, "rrr\n", 4);
}