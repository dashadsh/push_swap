/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:28:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/31 13:07:41 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
/* 
determines various properties of the various variable types:
INT_MIN, INT_MAX ... 
*/
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
}					t_node;

/* utils_atoi.c */
int		ft_atoi_ps(const char *s);

/* utils_input.c */
int		is_digit(char c);
int		is_sign(char c);
int		invalid_argument(char **av);
int		duplicate_found(char **av);
int		is_sorted(char **av);

void	max_min_int_checker(char **av); //NEW
void	input_checker(int ac, char **av); //NEW

/* utils_instructions.c */
void	push(t_node **head_a, t_node **head_b, char c);
void	swap(t_node **head, char c);
void	rotate(t_node **head, char c);
void	r_rotate(t_node **head, char c);

/* utils_instructions2.c */
void	swap_two(t_node **head_a, t_node **head_b);
void	rotate_two(t_node **head_a, t_node **head_b);
void	r_rotate_two(t_node **head_a, t_node **head_b);

/*utils_indexing */
int		stack_size(t_node	*head);
void	add_index(t_node **head, int stack_size);
// void	print_index(t_node *start_node); //for testing

/* push_swap.c */
void	bigsort(t_node **stack_a, t_node **stack_b);
int		main(int ac, char **av);

/* utils_ll.c */
t_node	*ft_lstlast(t_node *head);
t_node	*create_node(int number);
t_node	*frontal_insertion(t_node *head, t_node *new);
t_node	*create_empty_stack(void);
t_node	*create_filled_stack(int ac, char **av);
void	print_list(t_node *start_node);

/* triplesort.c */
int		find_max_value(t_node *head);
void	triplesort(t_node **head);

/* push_all_to_b.c */
void	push_to_b_except_three(t_node **stack_a, t_node **stack_b);

/* utils_positions.c */
void	calculate_positions(t_node **head);
int		lowest_index_position(t_node **head);
int		find_target_position(t_node **head_a, int index_b);
void	add_target_positions(t_node **head_a, t_node **head_b);
// void	print_positions(t_node *head);
// void	print_target_positions(t_node	*head_b);

/* cost_calculation.c */
void	get_costs(t_node **head_a, t_node **head_b);
int		absolute_nb(int nb);
void	do_minimal_move(t_node **head_a, t_node **head_b);
// void	print_costs(t_node *head_b);

/* utils_prepare.c */
void	prepare_a(t_node **head_a, int cost_a);
void	prepare_b(t_node **head_b, int cost_b);
void	prepare_two_stacks(t_node **head_a, t_node **head_b,
			int cost_a, int cost_b);

/* utils_final_rotation.c */
void	final_rotation(t_node **head);

/* utils_free.c */
void	free_list(t_node **head);
void	free_lists(t_node **head_a, t_node **head_b);

#endif