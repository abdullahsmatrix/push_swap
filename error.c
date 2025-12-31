/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:13:29 by amamun            #+#    #+#             */
/*   Updated: 2025/12/24 23:39:52 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;
    
    if (NULL == stack)
        return ;
    current = *stack;
    while(current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

int error_syntax(char *str_nbr)
{
    if (!(*str_nbr == '+' || *str_nbr == '-'
            || (*str_nbr >= '0' && *str_nbr <= '9')))
            return(1);
    if (*str_nbr == '+' || *str_nbr == '-'
        && !(*str_nbr >= '0' && *str_nbr <= '9'))
        return (1);
    while(*++str_nbr)
    {
        if (!(str_nbr >= '0' && str_nbr <= '9'))
            return (1);
    }
    return (0);       
}
void error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
    free_stack(a);
    if (flag_argc_2)
        free_matrix(argv);
    write(2, "Error\n", 6);
    exit(1);
}