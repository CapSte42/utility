/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_are_cool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:34:24 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacks_are_cool(t_list **stack_a, t_list **stack_b)
{
	t_data	*current_data;
	t_data	*next_data;
	t_list	*temp;

	if (*stack_b)
	{
		return (0);
	}
	temp = *stack_a;
	while (temp != NULL && temp->next != NULL)
	{
		current_data = (t_data *)(temp->content);
		next_data = (t_data *)(temp->next->content);
		if (current_data->value > next_data->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
