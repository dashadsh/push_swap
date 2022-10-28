#include "push_swap.h"

void	final_rotation(t_node **head)
{
	int	lowest_p;

	lowest_p = lowest_index_position(head);
	if (lowest_p <= stack_size(*head) / 2)
	{
		while(lowest_p)
		{
			rotate(head, 'a');
			lowest_p--;
		}
	}
	else
	{
		r_rotate(head, 'a'); // not &
		lowest_p++;
	}
}
//incompatible pointer types passing 't_node ***' (aka 'struct s_node ***') to parameter of type 't_node **' (aka 'struct s_node **'); remove & [-Wincompatible-pointer-types]
//                 r_rotate(&head, 'a');
//                          ^~~~~
// ./push_swap.h:62:24: note: passing argument to parameter 'head' here
// void    r_rotate(t_node **head, char c);
//                           ^