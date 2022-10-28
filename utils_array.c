#include "push_swap.h"

/* FOR TESTING */
int	*array_creator(int ac, char **av) 
{
	int	*array;
	int	i;

	i = 1;
	array = malloc(sizeof(int) * ac); // ac, so we have place for \0 
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i - 1] = ft_atoi_ps(av[i]);
		i++;
	}
	return (array);
}
