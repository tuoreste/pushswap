/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:47:22 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/08 09:48:10 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	if (sort_checked(*stack_a))
		return ;
	if (((*stack_a)-> next->next->data > (*stack_a)->data)
		&& ((*stack_a)->data > (*stack_a)->next->data))
		sa(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		if ((*stack_a)->next->data > (*stack_a)-> next->next->data)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
	if ((*stack_a)->next->data > (*stack_a)-> next -> next -> data)
	{
		if ((*stack_a)->next->next->data > (*stack_a)->data)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

int	find_lowest(t_list **stack, int val)
{
	t_list	*head;
	int		lowest;

	head = *stack;
	lowest = head -> index;
	while (head -> next)
	{
		head = head -> next;
		if ((head -> index < lowest) && head -> index != val)
			lowest = head -> index;
	}
	return (lowest);
}

int	what_size(t_list **stack, int index)
{
	t_list	*head;
	int		size;

	size = 0;
	head = *stack;
	while (head)
	{
		if (head -> index == index)
			break ;
		size++;
		head = head -> next;
	}
	return (size);
}

void	four_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (sort_checked(*stack_a))
		return ;
	size = what_size(stack_a, find_lowest(stack_a, -1));
	if (size == 1)
		ra(stack_a);
	else if (size == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (size == 3)
		rra(stack_a);
	if (sort_checked(*stack_a))
		return ;
	pb(stack_b, stack_a);
	three_sort(stack_a);
	pa(stack_a, stack_b);
}

void	five_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = what_size(stack_a, find_lowest(stack_a, -1));
	if (sort_checked(*stack_a))
		return ;
	if (size == 1)
		ra(stack_a);
	else if (size == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (size == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (size == 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	four_sort(stack_a, stack_b);
	pa(stack_a, stack_b);
}
