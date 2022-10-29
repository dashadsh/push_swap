/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:51:19 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/10/29 10:51:20 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_min_int_checker(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		ft_atoi_ps(av[i]);
		i++;
	}
}

void	input_checker(int ac, char **av)
{
	if (ac == 1)
		exit (0);
	if (invalid_argument(av))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (duplicate_found(av))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	max_min_int_checker(av);
	if (is_sorted(av))
		exit (0);
}
