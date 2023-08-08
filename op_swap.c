/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:17:17 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/08 09:48:02 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop(t_list **stack)
{
	t_list	*top_node;

	top_node = *stack;
	if (top_node == NULL)
		return (NULL);
	*stack = top_node -> next;
	top_node -> next = NULL;
	return (top_node);
}

void	sa(t_list **stack)
{
	t_list	*elem_a;
	t_list	*elem_b;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	elem_a = pop(stack);
	elem_b = pop(stack);
	ft_lstadd_front(stack, elem_a);
	ft_lstadd_front(stack, elem_b);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	t_list	*elem_a;
	t_list	*elem_b;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	elem_a = pop(stack);
	elem_b = pop(stack);
	ft_lstadd_front(stack, elem_a);
	ft_lstadd_front(stack, elem_b);
	write(1, "sb\n", 3);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
