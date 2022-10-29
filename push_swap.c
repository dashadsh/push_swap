/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:49:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:49:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (ac >= 5)
	{
		push_to_b_except_three(&stack_a, &stack_b);
		triplesort(&stack_a);
		while (stack_b)
		{
			add_target_positions(&stack_a, &stack_b);
			get_costs(&stack_a, &stack_b);
			do_minimal_move(&stack_a, &stack_b);
		}
	}
	while (stack_a->index != 1)
		final_rotation(&stack_a);
	return (0);
}

/*	print_list(stack_a); */