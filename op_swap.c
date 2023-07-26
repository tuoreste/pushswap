/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:26:13 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/25 16:31:59 by otuyishi         ###   ########.fr       */
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
	t_list	*first_elem;
	t_list	*second_elem;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	first_elem = pop(stack);
	second_elem = pop(stack);
	ft_lstadd_front(stack, first_elem);
	ft_lstadd_front(stack, second_elem);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	t_list	*first_elem;
	t_list	*second_elem;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	first_elem = pop(stack);
	second_elem = pop(stack);
	ft_lstadd_front(stack, first_elem);
	ft_lstadd_front(stack, second_elem);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
