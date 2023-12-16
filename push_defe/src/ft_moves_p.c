/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:27:05 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_px(t_list **stack_reciver, t_list **stack_giver)
{
	t_list	*tmp_giv;

	if (!*stack_giver)
		return (1);
	tmp_giv = (*stack_giver)->next;
	ft_lstadd_front(stack_reciver, *stack_giver);
	*stack_giver = tmp_giv;
	return (0);
}
