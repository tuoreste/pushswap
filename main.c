/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:23:25 by otuyishi          #+#    #+#             */
/*   Updated: 2023/07/28 11:11:11 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

char	*more_args(int argc, char **argv)
{
	t_or	t;

	t.input = NULL;
	t.total_length = 0;
	t.i = 1;
	t.pos = 0;
	while (t.i < argc)
		t.total_length += ft_strlen(argv[t.i++]);
	t.total_length += argc - 2;
	t.input = (char *)malloc(t.total_length + 1);
	if (t.input == NULL)
		error_exit();
	t.i = 1;
	while (t.i < argc)
	{
		t.j = 0;
		while (argv[t.i][t.j] != '\0')
			t.input[t.pos++] = argv[t.i][t.j++];
		if (t.i < argc - 1)
			t.input[t.pos++] = ' ';
		t.i++;
	}
	t.input[t.pos] = '\0';
	return (t.input);
}

void	fill_stack_a(t_list **stack_a, t_or t)
{
	t.ptr = t.input;
	while (*t.ptr)
	{
		if (!is_whitespace(*t.ptr) && !ft_isdigit(*t.ptr)
			&& *t.ptr != '+' && *t.ptr != '-')
		{
			free(t.input);
			free_list(*stack_a);
			error_exit();
		}
		t.value = parse_int(t.ptr, &t.ptr);
		if (t.ptr == t.input)
		{
			free(t.input);
			free_list(*stack_a);
			error_exit();
		}
		push_back(stack_a, t.value);
	}
	free(t.input);
}

int	main(int argc, char **argv)
{
	t_or	t;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error_exit();
	else if (argc == 2)
		t.input = ft_strdup(argv[1]);
	else
		t.input = more_args(argc, argv);
	if (!t.input)
		error_exit();
	fill_stack_a(&stack_a, t);
	has_duplicates(stack_a);
	if (stack_a && sort_checked(stack_a))
		return (1);
	if (!stack_a)
		error_exit();
	t.stack_n = ft_lstsize(stack_a);
	index_stack_items(stack_a, t.stack_n);
	push_swap(&stack_a, &stack_b, t.stack_n);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
