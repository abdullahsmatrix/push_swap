/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:13:53 by amamun            #+#    #+#             */
/*   Updated: 2025/12/31 19:41:16 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h> // bool data type
# include <stdio.h> // remove before submit!!!!//
# include <limits.h>


typedef struct s_stack_node
{
    int value;
    int current_position;
    int final_index;
    int push_cost;
    bool above_median;
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}                t_stack_node;

int	ft_strlcpy(char *dest, char const *src, size_t n);
int	ft_strlen(char const *str);
char **ft_split(char const *s, char c);
void init_nodes(t_stack_node *a, t_stack_node *b);

void free_stack(t_stack_node **stack);
int stack_len(t_stack_node *stack);
t_stack_node *find_last_node(t_stack_node *current);
t_stack_node *find_largest(t_stack_node *stack);


#endif