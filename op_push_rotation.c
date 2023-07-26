/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:54:56 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/25 16:48:07 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)-> next;
		ft_lstadd_front(stack_b, temp);
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)-> next;
		ft_lstadd_front(stack_a, temp);
	}
	write(1, "pb\n", 3);
}

//rotation a
void	ra(t_list **stack)
{
	t_list	*old_top;
	t_list	*lst;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	old_top = *stack;
	*stack = old_top ->next;
	old_top -> next = NULL;
	lst = ft_lstlast(*stack);
	lst -> next = old_top;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	t_list	*old_top;
	t_list	*lst;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	old_top = *stack;
	*stack = old_top ->next;
	old_top -> next = NULL;
	lst = ft_lstlast(*stack);
	lst -> next = old_top;
	write(1, "rb\n", 3);
}

//rotation both a and b
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
