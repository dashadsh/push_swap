/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:51:23 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:51:24 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushed from stack_a to stack_b */
void	push(t_node **head_a, t_node **head_b, char c)
{
	t_node	*head_tmp;

	head_tmp = *head_a;
	*head_a = (*head_a)->next;
	head_tmp->next = *head_b;
	*head_b = head_tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	swap(t_node **head, char c)
{
	t_node	*newhead;

	newhead = *head;
	*head = (*head)->next;
	newhead->next = (*head)->next;
	(*head)->next = newhead;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_node **head, char c)
{
	t_node	*headless;
	t_node	*tale;

	tale = ft_lstlast(*head);
	headless = (*head)->next;
	(*head)->next = NULL;
	tale->next = *head;
	*head = headless;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	r_rotate(t_node **head, char c)
{
	t_node	*newhead;
	t_node	*second_node;

	newhead = ft_lstlast(*head);
	second_node = *head;
	while (second_node->next->next != NULL)
		second_node = second_node->next;
	second_node->next = NULL;
	newhead->next = *head;
	*head = newhead;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
