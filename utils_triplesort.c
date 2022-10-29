#include "push_swap.h"

/*
1 3 2 ->rra ->2 1 3 ->sa ->1 2 3
2 1 3 ->sa  ->1 2 3
2 3 1 ->rra ->1 2 3 
3 1 2 ->ra  ->1 2 3 
3 2 1 ->ra  ->2 1 3 ->sa ->1 2 3

If value of the first number is highest => ra
If value of the second number is highest => rra,
Then, if the value of the first number is bigger than 
the value of the second number => sa.
*/

int	find_max_value(t_node *head)
{
	int		maxvalue;

	maxvalue = head->value;
	while (head)
	{
		if (head->value > maxvalue)
			maxvalue = head->value;
		head = head->next;
	}
	return (maxvalue);
}

void	triplesort(t_node **head)
{
	int		maxvalue;
	// if (is_sorted_stack(*head))
	if ((*head)->value < (*head)->next->value &&
		(*head)->next->value < (*head)->next->next->value)
		return ;
	maxvalue = find_max_value(*head);
	if ((*head)->value == maxvalue)
		rotate(head, 'a');
	else if ((*head)->next->value == maxvalue)
		r_rotate(head, 'a');
	if ((*head)->value > (*head)->next->value)
		swap(head, 'a');
}
