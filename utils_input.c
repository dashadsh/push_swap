#include "push_swap.h"

/* 
checks if the char is a digit.
returns 1 if the char is a digit, 0 if not 
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* 
checks if the char is  + or -.
return: 1 if the char is a sign, 0 if not 
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/*
only positive, negative int, not checking for MAXINT, MININT yet. 
allowed input +1, -1, 0, +0000001, 13023457862938457678923465
forbidden input ++1, +-1, adsflkh, +1+1
will get rid of 0 and + in +0000001, check for MAXINT-MININT using atoi function
will return 1 if arg is INVALID
*/
int	invalid_argument(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (is_sign(av[i][j]) && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicate_found(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi_ps(av[i]) == ft_atoi_ps(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* also works for 1 digit only */
int	is_sorted(char **av)
{
	int	i;

	i = 1;
	while (av[i + 1])
	{
		if (ft_atoi_ps(av[i]) > ft_atoi_ps(av[i + 1]))
			return (0);		
		i++;
	}
	return (1);
}
