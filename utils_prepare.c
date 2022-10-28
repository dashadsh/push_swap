#include "push_swap.h"

void	prepare_a(t_node **head_a, int cost_a)
{
	if (cost_a > 0)
		while (cost_a-- > 0)
			rotate(head_a, 'a');
	else if (cost_a < 0)
		while (cost_a++ < 0)
			r_rotate(head_a, 'a');
}

void	prepare_b(t_node **head_b, int cost_b)
{
	if (cost_b > 0)
		while (cost_b-- > 0)
			rotate(head_b, 'b');
	else if (cost_b < 0)
		while (cost_b++ < 0)
			r_rotate(head_b, 'b');
}

void	prepare_two_stacks(t_node **head_a, t_node **head_b,
		int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rotate_two(head_a, head_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		r_rotate_two(head_a, head_b);
		cost_a++;
		cost_b++;
	}
	prepare_a(head_a, cost_a); //SHOULD BE HERE _ NOT IN DO MOVE
	prepare_b(head_b, cost_b);
}
