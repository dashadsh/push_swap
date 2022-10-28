#include "push_swap.h"

/* 
calculate how many rotations it needs to place node
on top of stack_b

calculate how many rotations it needs to plase it's target node
on top of stack_a

positive for rotation
negative for reversed rotation
*/

void	get_costs(t_node **head_a, t_node **head_b)
{
	t_node	*tmp_a;
	int		size_a;
	t_node	*tmp_b;
	int		size_b;

	tmp_a = *head_a;
	tmp_b = *head_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		if (tmp_b->position <= size_b / 2)
			tmp_b->cost_b = tmp_b->position;
		else
			tmp_b->cost_b = -(size_b - tmp_b->position);
		if ((tmp_b->target_position <= size_a / 2))
			tmp_b->cost_a = tmp_b->target_position;
		else
			tmp_b->cost_a = -(size_a - tmp_b->target_position);
		tmp_b = tmp_b->next;
	}
}

int	absolute_nb(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	do_minimal_move(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;
	int		moves_min;
	int		cost_a;
	int		cost_b;

	tmp = *head_b;
	moves_min = INT_MAX;
	while (tmp)
	{
		if (absolute_nb(tmp->cost_a) + absolute_nb(tmp->cost_b)
			< moves_min)
		{
			moves_min = absolute_nb(tmp->cost_a) + absolute_nb(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	prepare_two_stacks(head_a, head_b, cost_a, cost_b);
	push(head_b, head_a, 'a');
}

/*
// FOR TESTING
void	print_costs(t_node *head_b)
{
	t_node	*tmp;

	tmp = head_b;
	while (tmp)
	{
		printf("%d ", tmp->cost_a);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = head_b;
	while (tmp)
	{
		printf("%d ", tmp->cost_b);
		tmp = tmp->next;
	}
	printf("\n");
}
*/
