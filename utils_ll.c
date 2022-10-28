#include "push_swap.h"

t_node	*ft_lstlast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	if (!head)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*create_node(int number)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->value = number;
	head->next = NULL;
	return (head);
}

t_node	*frontal_insertion(t_node *head, t_node *new)
{
	new->next = head;
	return (new);
}

/* create an empty stack */
t_node *create_empty_stack(void)
{ //malloc anyway??
	t_node	*head;

	head = NULL;
	return (head);
}

t_node	*create_filled_stack(int ac, char **av)
{
	t_node	*head;

	head = NULL;
	while (ac-- > 1)
		head = frontal_insertion(head, create_node(ft_atoi_ps(av[ac])));
	return (head);
}

// FOR TESTING
void	print_list(t_node *start_node)
{
	t_node	*tmp;

	tmp = start_node;
	while (tmp)
	{
		printf("%i ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
// while (tmp != NULL) // ALSO WORKS
// while (tmp->value != NULL) //1 2 3, then SEGFAULT
// while (tmp->value) //1 2 3, then SEGFAULT

