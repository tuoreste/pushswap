/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:36:40 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/02 16:53:31 by otuyishi         ###   ########.fr       */
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

void	has_duplicates(t_list *numbers)
{
	t_list	*current;
	t_list	*temp;

	current = numbers;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->data == current->data)
				error_exit();
			temp = temp->next;
		}
		current = current->next;
	}
	return ;
}

t_list	*create_node_index(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
		node->index = 0;
		node->next = NULL;
	}
	return (node);
}

void	push_back(t_list **head, int data)
{
	t_list	*current;

	if (!*head)
	{
		*head = create_node_index(data);
	}
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = create_node_index(data);
	}
}
