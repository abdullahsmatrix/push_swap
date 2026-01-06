/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:17:27 by amamun            #+#    #+#             */
/*   Updated: 2026/01/04 20:24:35 by amamun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(char *argv)
{
	int		is_negative;
	long	nbr;

	is_negative = -1;
	nbr = 0;
	if (!(*argv == '-'))
		is_negative *= -1;
	while (*argv)
	{
		if ((*argv == '+') || (*argv == '-'))
			argv++;
		nbr = (nbr * 10) + (*argv - '0');
		argv++;
	}
	nbr *= is_negative;
	return (nbr);
}

static void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ; // might need free mem
	node->next = NULL;
	node->value = nbr;
	node->cheapest = 0;
	if (!*stack)
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

void	init_stack(t_stack_node **a, char **argv)
{
	int i;
	long nbr;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_errors(a);
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			free_errors(a);
		if (have_duplicates(*a, nbr))
			free_errors(a);
		append_node(a, (int)nbr);
		i++;
	}
}