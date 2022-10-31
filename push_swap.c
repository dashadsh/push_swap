/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:49:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/31 13:06:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bigsort(t_node **stack_a, t_node **stack_b)
{
	add_target_positions(stack_a, stack_b);
	get_costs(stack_a, stack_b);
	do_minimal_move(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	input_checker(ac, av);
	stack_a = create_filled_stack(ac, av);
	stack_b = create_empty_stack();
	add_index(&stack_a, stack_size(stack_a));
	if (ac == 3)
		swap(&stack_a, 'a');
	else if (ac == 4)
		triplesort(&stack_a);
	else if (ac > 4)
	{
		push_to_b_except_three(&stack_a, &stack_b);
		triplesort(&stack_a);
		while (stack_b)
			bigsort(&stack_a, &stack_b);
		final_rotation(&stack_a);
	}
	free_lists(&stack_a, &stack_b);
	return (0);
}

/*	print_list(stack_a); */