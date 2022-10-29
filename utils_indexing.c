/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:51:05 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:51:06 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* counts nr of elements in a stack*/
int	stack_size(t_node	*head)
{
	int	size;

	size = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

/*
1st part:
iterate through entire linked list using ptr, 
find largest number (saving value to the maxvalue), 
save pointer to biggest node

2nd part: add index to biggest node equal to stack size

repeat with stacksize-1, iterate through numbers with 0 index only. 
node with highest index from the loop before stayes untouched. 
*/
void	add_index(t_node **head, int stack_size)
{
	t_node	*ptr;
	t_node	*maxnode;
	int		maxvalue;

	while (stack_size > 0)
	{
		ptr = *head;
		maxnode = NULL;
		maxvalue = INT_MIN;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->value == INT_MIN)
				ptr->index = 1;
			else if (ptr->index == 0 && ptr->value > maxvalue)
			{
				maxvalue = ptr->value;
				maxnode = ptr;
			}
			else
				ptr = ptr->next;
		}
		if (maxnode)
			maxnode->index = stack_size;
		stack_size -= 1;
	}
}

/* 
// FOR TESTING
void	print_index(t_node *start_node)
{
	t_node	*tmp;

	tmp = start_node;
	while (tmp)
	{
		printf("%i ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}
*/