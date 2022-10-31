/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:43:33 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/31 13:20:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **head)
{
	t_node	*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void	free_lists(t_node **head_a, t_node **head_b)
{
	free_list(head_a);
	free_list(head_b);
}

/*
void	error_exit(t_node **head_a, t_node **head_b)
{
	if (!(head_a) || !(*head_a))
		free_list(head_a);
	if (!(head_b) || !(*head_b))
		free_list(head_b);
	write(2, "Error\n", 6);
	exit (1); // or 1 ???
}
*/