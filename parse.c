/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:36:28 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/27 10:12:16 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	inspect(char *str, t_or t)
{
	if (t.result > INT_MAX / 10 \
	|| (t.result == INT_MAX / 10 && (*str - '0') > INT_MAX % 10))
		error_exit();
	if (t.result < INT_MIN / 10 \
	|| (t.result == INT_MIN / 10 && (*str - '0') > -(INT_MIN % 10)))
		error_exit();
}

int	parse_int(char *str, char **endptr)
{
	t_or	t;

	t.result = 0;
	t.sign = 1;
	str = skip_whitespace(str);
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == ' ' || *(str + 1) == '\0')
			error_exit();
		if (*str == '-')
			t.sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		inspect(str, t);
		t.result = t.result * 10 + (*str - '0');
		str++;
	}
	if (*str == '+' || *str == '-')
		error_exit();
	*endptr = str;
	return (t.result * t.sign);
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
