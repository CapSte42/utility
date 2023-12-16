/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:24:13 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	ft_min_dist(t_list *stack_a)
{
	t_list	*node;
	ssize_t	i;
	ssize_t	size;

	node = stack_a;
	i = 0;
	size = ft_lstsize(stack_a);
	while (((t_data *)node->content)->index != 1)
	{
		i++;
		node = node->next;
	}
	if (i <= size / 2)
		return (i);
	else
		return (i - size);
}

char	*ft_last_rotate(t_list **stack_a, char *moves)
{
	ssize_t	min_dist;

	min_dist = ft_min_dist(*stack_a);
	while (min_dist != 0)
	{
		if (min_dist > 0)
		{
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			min_dist--;
		}
		else if (min_dist < 0)
		{
			ft_rrx(stack_a);
			moves = ft_strjoin(moves, "rra\n");
			min_dist++;
		}
	}
	return (moves);
}
