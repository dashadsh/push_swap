/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:51:30 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:51:31 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_node **head_a, t_node **head_b)
{
	swap(head_a, 0);
	swap(head_b, 0);
	write(1, "ss\n", 3);
}

void	rotate_two(t_node **head_a, t_node **head_b)
{
	rotate(head_a, 0);
	rotate(head_b, 0);
	write(1, "rr\n", 3);
}

void	r_rotate_two(t_node **head_a, t_node **head_b)
{
	r_rotate(head_a, 0);
	r_rotate(head_b, 0);
	write(1, "rrr\n", 4);
}
