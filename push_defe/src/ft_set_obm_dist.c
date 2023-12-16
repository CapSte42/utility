/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_obm_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:54 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_set_obm_dista(t_list **stack_a, size_t index, size_t size_b)
{
	t_list	*node;
	size_t	i;
	size_t	size_a;

	i = 0;
	node = *stack_a;
	size_a = ft_lstsize(*stack_a);
	while (node != NULL)
	{
		if ((((t_data *)node->content)->index) == index + 1)
		{
			if (i <= size_a / 2)
				((t_data *)node->content)->dist = i;
			else
				((t_data *)node->content)->dist = i - size_a;
			return (node->content);
		}
		i++;
		node = node->next;
	}
	if (index > ft_max_index(*stack_a, size_b + size_a))
		return (ft_set_obm_dista(stack_a,
				ft_min_index(*stack_a, size_b + size_a) - 1, size_b));
	else
		return (ft_set_obm_dista(stack_a, index + 1, size_b));
}

void	ft_set_obm_distb(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	size_t	i;
	size_t	size_b;

	node = *stack_b;
	i = 0;
	size_b = ft_lstsize(*stack_b);
	while (node != NULL)
	{
		if (i <= size_b / 2)
			((t_data *)node->content)->dist = i;
		else
			((t_data *)node->content)->dist = i - size_b;
		((t_data *)node->content)->obm = ft_set_obm_dista(stack_a,
				((t_data *)node->content)->index, size_b);
		i++;
		node = node->next;
	}
}

/*
int	main()
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*node;
	t_data	*data;
	size_t	arr_a[8] = {7, 16, 4, 6, 1, 14, 15, 10};
	size_t	arr_b[8] = {11, 5, 2, 3, 8, 11, 12, 13};
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < 8)
	{
		data = malloc(sizeof(t_data));
		data->index = arr_a[i];
		data->value = arr_a[i];
		data->dist = 0;
		data->obm = NULL;
		ft_lstadd_back(&stack_a, ft_lstnew(data));
		i++;
	}
	node = stack_a;
	printf("\nstack_a:\n");
	while (node != NULL)
	{
		printf("index: %zu, value: %zd, dist: %zd",
				((t_data *)node->content)->index,
				((t_data *)node->content)->value,
				((t_data *)node->content)->dist);
		node = node->next;
		printf("\n");
	}
	i = 0;
	while (i < 8)
	{
		data = malloc(sizeof(t_data));
		data->index = arr_b[i];
		data->value = arr_b[i];
		data->dist = 0;
		data->obm = NULL;
		ft_lstadd_back(&stack_b, ft_lstnew(data));
		i++;
	}
	node = stack_b;
	printf("\nstack_b:\n");
	while (node != NULL)
	{
		printf("index: %zu, value: %zd, dist: %zd",
				((t_data *)node->content)->index,
				((t_data *)node->content)->value,
				((t_data *)node->content)->dist);
		node = node->next;
		printf("\n");
	}
	ft_set_obm_distb(&stack_a, &stack_b);
	node = stack_b;
	printf("\nstack_b final:\n");
	while (node != NULL)
	{
		printf("index: %zu, value: %zd, dist: %zd, obm: %zd",
			((t_data *)node->content)->index,
			((t_data *)node->content)->value,
			((t_data *)node->content)->dist,
			(((t_data *)node->content)->obm)->dist);
		node = node->next;
		printf("\n");
	}
	node = ft_obm_score(stack_b);
	printf("index : %zu\ndist: %zd\nobm index: %zu\nobm dist: %zd\n",
		((t_data *)node->content)->index,
		((t_data *)node->content)->dist,
		(((t_data *)node->content)->obm)->index,
		(((t_data *)node->content)->obm)->dist);
	return (0);
}
*/