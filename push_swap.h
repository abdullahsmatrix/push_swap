/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:16:08 by amamun            #+#    #+#             */
/*   Updated: 2026/01/05 19:42:32 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;
//////////////Sorting & ALGO//////////
void					tiny_sort(t_stack_node **a);
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					set_current_position(t_stack_node *stack);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
/////////////Libft////////////////////
char					**ft_split(char *s, char c);
int						ft_strlcpy(char *dest, char const *src, size_t n);
int						ft_strlen(char const *str);

//////////////Parsing/////////////////
void					init_stack(t_stack_node **a, char **argv);
int						syntax_error(char *argv);
int						have_duplicates(t_stack_node *a, int nbr);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);

///////////////Operations/////////////
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);

//////////////Stack Utils/////////////
t_stack_node			*find_last_node(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_largest_node(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
t_stack_node			*find_smallest(t_stack_node *stack);

#endif