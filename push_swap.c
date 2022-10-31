/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:49:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/31 11:53:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_more(t_node **stack_a, t_node **stack_b)
// 	{
// 		push_to_b_except_three(stack_a, stack_b);
// 		triplesort(stack_a);
// 		while (stack_b)
// 		{
// 			add_target_positions(stack_a, stack_b);
// 			get_costs(stack_a, stack_b);
// 			do_minimal_move(stack_a, stack_b);
// 		}
// 		while ((*stack_a)->index != 1)
// 			final_rotation(stack_a);
// 	}

	
// {
// 	pass_to_b(a_stack, b_stack);
// 	sort_three(a_stack);
// 	while (*b_stack)
// 	{
// 		add_pos(a_stack, b_stack);
// 		find_tp(a_stack, b_stack);
// 		calc_cost(a_stack, b_stack);
// 		exec_actions(a_stack, b_stack);
// 		pa(a_stack, b_stack);
// 	}
// 	final_sort(a_stack);
// }

// void	ft_sort(t_stack **a_stack, t_stack **b_stack)
// {
// 	int		a_stack_len;

// 	a_stack_len = ft_lst_len(a_stack);
// 	if (a_stack_len == 2)
// 	{
// 		sa(a_stack, 0);
// 		return ;
// 	}
// 	if (a_stack_len == 3)
// 	{
// 		sort_three(a_stack);
// 		return ;
// 	}	
// 	sort_more(a_stack, b_stack);
// }

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
		{
			add_target_positions(&stack_a, &stack_b);
			get_costs(&stack_a, &stack_b);
			do_minimal_move(&stack_a, &stack_b);
		}
		final_rotation(&stack_a);
	}
//	print_list(stack_a);
	free_lists(&stack_a, &stack_b);
	return (0);
}

/*	print_list(stack_a); */