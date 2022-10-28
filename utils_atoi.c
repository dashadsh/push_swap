#include "push_swap.h"

int	ft_atoi_ps(const char *s)
{
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value = (value * 10) + (*s - '0');
		s++;
	}
	if (value * sign < -2147483648 || value * sign > 2147483647)
	{
		write(2, "Error\n", 6); // should we free smth??
		exit(0);
	}
	return (sign * value);
}
