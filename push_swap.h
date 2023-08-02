/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 07:25:25 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/02 20:48:58 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
	struct node	*stack_a;
	struct node	*stack_b;
}				t_list;

typedef struct s_or
{
	int		i;
	int		j;
	int		result;
	int		sign;
	int		stack_n;
	int		value;
	int		total_length;
	int		pos;
	char	*input;
	char	*ptr;
}			t_or;

//main//
int			main(int argc, char **argv);
void		free_list(t_list *head);
void		index_stack_items(t_list *stack_a, int size);
void		error_exit(void);
//Libft//
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(char const *str, char c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
t_list		*ft_lstnew(void *content);
void		ft_putendl_fd(char *s, int fd);
//op_push_and_rotation//
//push
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_b, t_list **stack_a);
//rotate
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
//op_rev_rotation//
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);
//op_swap//
t_list		*pop(t_list **stack);
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
//push_swap//
void		rest_sort(t_list *stack_a, t_list *stack_b);
void		switch_to_a(t_list **stack_a, t_list **stack_b, int len);
void		push_swap(t_list **stack_a, t_list **stack_b, int stack_n);
int			near_sqr_to_no(int no);
int			rotate_count(t_list *str, int index);
//push_sort
int			sort_checked(t_list *stack);
void		three_sort(t_list *stack_a);
void		four_sort(t_list *stack_a, t_list *stack_b);
void		five_sort(t_list *stack_a, t_list *stack_b);
//validating//
void		has_duplicates(t_list *numbers);
t_list		*create_node_index(int data);
void		push_back(t_list **head, int data);
//parse//
int			is_whitespace(char c);
char		*skip_whitespace(char *str);
int			parse_int(char *str, char **endptr);
void		index_stack_items(t_list *stack_a, int size);

#endif
