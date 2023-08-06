/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:29:18 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/06 21:29:39 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reverse_rotate a
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

//reverse_rotate b
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

//reverse_rotate both a and b
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	write(1, "rrr\n", 4);
}
