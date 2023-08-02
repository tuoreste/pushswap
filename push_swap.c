/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:23:31 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/02 21:18:09 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_count(t_list *str, int index)
{
	int	no;

	no = 0;
	while (str && str->index != index)
	{
		str = str->next;
		no++;
	}
	return (no);
}

int	near_sqr_to_no(int no)
{
	int	i;

	i = 0;
	while (i * i < no)
		i++;
	return (i - 1);
}

void	switch_to_a(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;

	i = 0;
	while (len--)
	{
		i = rotate_count(*stack_b, len);
		if (2 * i > len)
		{
			while ((*stack_b)->index != len)
				rrb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != len)
				rb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}

void	rest_sort(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	len;
	int	hold;

	i = 0;
	len = ft_lstsize(stack_a);
	hold = near_sqr_to_no(len) * 1.41;
	if (sort_checked(stack_a))
		return ;
	while (stack_a)
	{
		if ((stack_a)->index <= hold + i)
		{
			pb(&stack_a, &stack_b);
			if ((stack_b)->index <= i++)
				rb(&stack_b);
		}
		else
			ra(&stack_a);
	}
	switch_to_a(&stack_a, &stack_b, len);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int stack_n)
{
	if (stack_n == 0)
		return ;
	if (stack_n == 2 && !sort_checked(*stack_a))
		sa(stack_a);
	else if (stack_n == 3)
		three_sort(*stack_a);
	else if (stack_n == 4)
		four_sort(*stack_a, *stack_b);
	else if (stack_n == 5)
		five_sort(*stack_a, *stack_b);
	else
		rest_sort(*stack_a, *stack_b);
	return ;
}
