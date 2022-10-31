/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_final_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:50:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/31 11:34:46 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_node **head)
{
	int	lowest_p;

	while ((*head)->index != 1)
	{
		lowest_p = lowest_index_position(head);
		if (lowest_p <= stack_size(*head) / 2)
		{
			while (lowest_p)
			{
				rotate(head, 'a');
				lowest_p--;
			}
		}
		else
		{
			r_rotate(head, 'a');
			lowest_p++;
		}
	}
}

/*
void	final_rotation(t_node **head)
{
	int	lowest_p;

	lowest_p = lowest_index_position(head);
	if (lowest_p <= stack_size(*head) / 2)
	{
		while (lowest_p)
		{
			rotate(head, 'a');
			lowest_p--;
		}
	}
	else
	{
		r_rotate(head, 'a');
		lowest_p++;
	}
}
*/
