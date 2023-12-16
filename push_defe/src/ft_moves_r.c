/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:26:45 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rx(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	first = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = first;
	return (0);
}

int	ft_rrx(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (1);
	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	ft_lstadd_front(stack, last);
	second_last->next = NULL;
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	return (ft_rx(stack_a) + ft_rx(stack_b));
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	return (ft_rrx(stack_a) + ft_rrx(stack_b));
}
