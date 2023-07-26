/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:23:02 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/26 18:12:45 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_checked(t_list *stack)
{
	if (stack)
	{
		while (stack -> next != NULL)
		{
			if (stack -> data > stack -> next -> data)
				return (0);
			stack = stack -> next;
		}
	}
	return (1);
}

void	three_sort(t_list *stack_a)
{
	if ((stack_a->next->next->data > stack_a->data)
		&& (stack_a->data > stack_a->next->data))
		sa(&stack_a);
	if (stack_a->data > stack_a->next->data)
	{
		if (stack_a->next->data > stack_a->next->next->data)
		{
			sa(&stack_a);
			rra(&stack_a);
		}
		else
			ra(&stack_a);
	}
	if (stack_a->next->data > stack_a->next->next->data)
	{
		if (stack_a->next->next->data > stack_a->data)
		{
			sa(&stack_a);
			ra(&stack_a);
		}
		else
			rra(&stack_a);
	}
}

int	lower_index(t_list *stack)
{
	int		lower_x;
	t_list	*curr;

	curr = stack->next;
	lower_x = curr->index;
	while (curr->next)
	{
		curr = curr->next;
		if (curr->index < lower_x)
			lower_x = curr->index;
	}
	return (lower_x);
}

void	seven_sort(t_list *stack_a, t_list *stack_b)
{
	int	lower_x;
	int	i;
	int	no;

	i = 0;
	no = stack_a->data;
	while (i++ < no - 3)
	{
		lower_x = lower_index(stack_a);
		if (rotate_count(stack_a->next, lower_x) <= no - lower_x - \
			rotate_count(stack_a->next, lower_x))
			while (stack_a->next->index != lower_x)
				ra(&stack_a);
		else
			while (stack_a->next->index != lower_x)
				rra(&stack_a);
		if (sort_checked(stack_a) && stack_b->data == 0)
			return ;
		pb(&stack_b, &stack_a);
	}
	three_sort(stack_a);
	i = 0;
	while (i++ < no - 3)
		pa(&stack_a, &stack_b);
}
