/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:12:25 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/07 13:34:20 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack)
{
	t_list	*last;
	t_list	*second_lst;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	last = ft_lstlast(*stack);
	second_lst = *stack;
	while (second_lst -> next != last)
		second_lst = second_lst -> next;
	last -> next = *stack;
	*stack = last;
	second_lst -> next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	t_list	*last;
	t_list	*second_lst;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	last = ft_lstlast(*stack);
	second_lst = *stack;
	while (second_lst -> next != last)
		second_lst = second_lst -> next;
	last -> next = *stack;
	*stack = last;
	second_lst -> next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	write(1, "rrr\n", 4);
}
