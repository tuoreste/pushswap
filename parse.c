/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:28:15 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/08 09:48:06 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack_items(t_list *stack_a, int size)
{
	long long	data;
	t_list		*end;
	t_list		*ptr;

	while (--size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		end = NULL;
		while (ptr != NULL)
		{
			if (ptr -> data == INT_MIN && ptr -> index == 0)
				ptr -> index = 0;
			if (ptr -> data > data && ptr -> index == 0)
			{
				data = ptr -> data;
				end = ptr;
			}
			ptr = ptr -> next;
		}
		if (end != NULL)
			end -> index = size;
	}
}

void	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
			i++;
		if (str[i + 1] && ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]))
			error_exit();
		if (ft_isdigit(str[i]))
			i++;
		else
			error_exit();
	}
}

long long	parse_int(char *str)
{
	t_or	t;

	t.result = 0;
	t.sign = 1;
	is_digit(str);
	t.result = ft_atoi(str);
	if (t.result > INT_MAX || t.result < INT_MIN)
		error_exit();
	return (t.result);
}
