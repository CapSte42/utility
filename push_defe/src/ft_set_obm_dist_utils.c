/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_obm_dist_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:44 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_max_index(t_list *stack_a, size_t size)
{
	t_list	*node;
	size_t	index;

	index = size;
	while (index > 0)
	{
		node = stack_a;
		while (node != NULL)
		{
			if (((t_data *)node->content)->index == index)
				return (index);
			node = node->next;
		}
		index--;
	}
	return (0);
}

size_t	ft_min_index(t_list *stack_a, size_t size)
{
	t_list	*node;
	size_t	index;

	index = 1;
	while (index <= size)
	{
		node = stack_a;
		while (node != NULL)
		{
			if (((t_data *)node->content)->index == index)
				return (index);
			node = node->next;
		}
		index++;
	}
	return (0);
}
