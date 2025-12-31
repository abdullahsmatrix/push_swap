/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:27:56 by amamun            #+#    #+#             */
/*   Updated: 2025/12/30 21:29:37 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void append_node(t_stack_node **stack, int nbr)
{
    t_stack_node *node;
    t_stack_node *last_node;
    
    if (NULL == stack)
        return (NULL);
    node = malloc(sizeof(t_stack_node));
        if (node == NULL)
            return (NULL);
    node->next = NULL;
    node->value = nbr;
    if (NULL == *stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

static long ft_atol(char *str)
{
    long num;
    int isneg;
    int i;
    
    num = 0;
    isneg = 1;
    i = 0;
    
    while (str[i] && (str[i] == ' ' || str[i] == '\t'
            || str[i] == '\n' || str[i] == '\r'
            || str[i] == '\v' || str[i] == '\f'))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num * isneg);
}

void stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
    long nbr;
    int i;
    
    i = 0;
    while (argv[i])
    {
        if(error_syntax(argv[i]))
            error_free(a, argv, flag_argc_2);
        nbr = ft_atol(argv[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, argv, flag_argc_2);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, flag_argc_2);
        append_node(a, (int)nbr);
        i++;
    }
    if (flag_argc_2)
        free_matrix(argv);
}