#include "push_swap.h"

/*
check if the number on top of the stack has smaller index.
push to B. otherwise rotate stack A first.

when lower indexes are in stack B, continue with bigger values */
void	push_to_b_except_three(t_node **head_a, t_node **head_b)
{
	int	stacksize_a;
	int	pushed;

	stacksize_a = stack_size(*head_a);
	pushed = 0;
	while (stacksize_a > 6 && stacksize_a / 2 > pushed)
	{
		if ((*head_a)->index <= stacksize_a / 2)
		{
			push(head_a, head_b, 'b');
			pushed++; 
		}
		else
			rotate(head_a, 'a');
	}
	while (stacksize_a - pushed > 3)
	{
		push(head_a, head_b, 'b');
		pushed++;
	}
}
