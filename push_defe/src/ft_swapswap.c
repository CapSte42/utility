/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:28 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swapswap_b(t_list **stack_b, size_t size)
{
	if ((((((t_data *)(*stack_b)->content)->index)
			< (((t_data *)(*stack_b)->next->content)->index))
			&& ((((t_data *)(*stack_b)->content)->index) > size / 2
			&& (((t_data *)(*stack_b)->next->content)->index) > size / 2))
			|| (((((t_data *)(*stack_b)->content)->index)
			< (((t_data *)(*stack_b)->next->content)->index))
			&& ((((t_data *)(*stack_b)->content)->index) <= size / 2
			&& (((t_data *)(*stack_b)->next->content)->index) <= size / 2)))
		return (1);
	return (0);
}

char	*ft_swapswap(t_list **stack_a, t_list **stack_b, char *moves)
{
	size_t	size;

	size = (size_t)(ft_lstsize(*stack_a) + ft_lstsize(*stack_b));
	if (((((t_data *)(*stack_a)->content)->index)
		> (((t_data *)(*stack_a)->next->content)->index))
		&& (((((t_data *)(*stack_a)->content)->index) > size / 2
		&& (((t_data *)(*stack_a)->next->content)->index) > size / 2)
		|| ((((t_data *)(*stack_a)->content)->index) <= size / 2
		&& (((t_data *)(*stack_a)->next->content)->index) <= size / 2)))
	{
		if (*stack_b != NULL && (*stack_b)->next != NULL)
		{
			if (ft_swapswap_b(stack_b, size) == 1)
			{
				ft_ss(stack_a, stack_b);
				moves = ft_strjoin(moves, "ss\n");
			}
		}
	}
	return (moves);
}
