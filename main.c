/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:07:49 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/08 09:47:38 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

char	**args_receiver(int arc, char **arv)
{
	t_or	t;
	char	**splitted;

	t.i = 1;
	t.pos = 0;
	if (arc == 2)
		t.input = ft_strdup(arv[1]);
	else
	{
		t.input = ft_strdup("");
		while (arv[t.i])
		{
			t.input = ft_strjoin(t.input, arv[t.i++]);
			t.input = ft_strjoin(t.input, " ");
		}
	}
	splitted = ft_split(t.input, ' ');
	free(t.input);
	return (splitted);
}

void	index_swap_free(t_list *stack_a, t_list *stack_b)
{
	t_or	t;

	t.stack_n = ft_lstsize(stack_a);
	index_stack_items(stack_a, t.stack_n);
	push_swap(&stack_a, &stack_b, t.stack_n);
	free_list(stack_a);
}

int	main(int argc, char **argv)
{
	t_or	t;
	char	**splitted;
	t_list	*stack_a;
	t_list	*stack_b;

	t.i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	splitted = args_receiver(argc, argv);
	while (splitted[t.i])
	{
		t.endptr = splitted[t.i++];
		t.res = parse_int(t.endptr);
		push_back(&stack_a, t.res);
		has_duplicates(stack_a);
	}
	free_str_arr(splitted);
	if (stack_a && sort_checked(stack_a))
		return (0);
	if (!stack_a)
		error_exit();
	index_swap_free(stack_a, stack_b);
	return (0);
}
