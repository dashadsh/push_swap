/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:51:39 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:53:59 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	if (!head)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*create_node(int number)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->value = number;
	head->next = NULL;
	return (head);
}

t_node	*frontal_insertion(t_node *head, t_node *new)
{
	new->next = head;
	return (new);
}

t_node	*create_empty_stack(void)
{
	t_node	*head;

	head = NULL;
	return (head);
}

t_node	*create_filled_stack(int ac, char **av)
{
	t_node	*head;

	head = NULL;
	while (ac-- > 1)
		head = frontal_insertion(head, create_node(ft_atoi_ps(av[ac])));
	return (head);
}

/*
void	print_list(t_node *start_node)
{
	t_node	*tmp;

	tmp = start_node;
	while (tmp)
	{
		printf("%i ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
*/