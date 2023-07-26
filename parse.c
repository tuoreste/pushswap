/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:36:28 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/26 19:33:59 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->next = NULL;
	}
	return (node);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

char	*skip_whitespace(char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

int	parse_int(char *str, char **endptr)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	str = skip_whitespace(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	*endptr = str;
	return (result * sign);
}

void	index_stack_items(t_list *stack_a, int size)
{
	int		data;
	t_list	*end;
	t_list	*ptr;

	while (--size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		end = NULL;
		while (ptr != NULL)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > data && ptr->index == 0)
			{
				data = ptr->data;
				end = ptr;
			}
			ptr = ptr->next;
		}
		if (end != NULL)
			end->index = size;
	}
}
