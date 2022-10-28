#include "push_swap.h"

void	calculate_positions(t_node **head)
{
	t_node	*ptr;
	int		i;

	ptr = *head;
	i = 0;
	while (ptr) // not *ptr
	{
		ptr->position = i;
		i++;
		ptr = ptr->next;
	}
}

/* 
USING INDEX TO FIND LOWEST POSITION
we need it if no superior index was found

we can calculate lowest position using index or value - it doesnt matter
*/
int	lowest_index_position(t_node **head)
{
	t_node	*tmp;
	int		lowest_i;
	int		lowest_p;

	tmp = *head;
	lowest_i = INT_MAX;
	calculate_positions(head);
	lowest_p = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_p = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_p);
}

/*
using index we are finding targt position in stack A 
for a single node in stack B

target postion is the smallest superior node
if there are no superior node, it will be smallest node of stack A
(use lowest_index_position function for that)
*/
int	find_target_position(t_node **head_a, int index_b)
{
	t_node	*tmp_a;
	int		target_i;
	int		target_p;

	tmp_a = *head_a;
	target_i = INT_MAX;
	target_p = 0;
	while (tmp_a)
	{
		if (tmp_a->index > index_b && tmp_a->index < target_i)
		{
			target_i = tmp_a->index;
			target_p = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_i == INT_MAX)
		return (lowest_index_position(head_a));
	return (target_p);
}

/*
using function for finding target postion for a single node
we assign target position for EVERY node in stack b
*/
void	add_target_positions(t_node **head_a, t_node **head_b)
{
	t_node	*tmp_b;

	tmp_b = *head_b;
	calculate_positions(head_a); // not calculated before
	calculate_positions(head_b);
	while (tmp_b)
	{
		tmp_b->target_position = find_target_position(head_a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}

/*
// FOR TESTING
void	print_positions(t_node *head)
{
	t_node	*tmp;

	tmp = head; // *?????? // if passig **head, star needed
	while (tmp) //!!! * if passing ** head // in main will be &
		{
			printf("%d ", tmp->position);
			tmp = tmp->next;
		}
	printf("\n");
}

// FOR TESTING
//print all target positions in stack A for stack B
void	print_target_positions(t_node	*head_b)
{
	t_node	*tmp_b;

	tmp_b = head_b;
	while (tmp_b)
	{
		printf("%d ", tmp_b->target_position);
		tmp_b = tmp_b->next;
	}
	printf("\n");
}
*/
