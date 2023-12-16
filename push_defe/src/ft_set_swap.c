/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:05 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:16:10 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sx_in(t_list **tmp)
{
	t_list	*swap;

	swap = (*tmp)->next;
	(*tmp)->next = (*tmp)->next->next;
	swap->next = (*tmp)->next->next;
	(*tmp)->next->next = swap;
	((t_data *)((*tmp)->next->content))->dist = 1;
}

void	ft_set_swap(t_list **lst)
{
	t_list	*tmp;
	size_t	min;
	size_t	max;

	min = ft_min_index(*lst, (size_t)ft_lstsize(*lst));
	max = ft_max_index(*lst, (size_t)ft_lstsize(*lst));
	if ((((t_data *)((*lst)->content))->index == min
		&& ((t_data *)((*lst)->next->content))->index == max)
		|| (((t_data *)((*lst)->content))->index
		== ((t_data *)((*lst)->next->content))->index + 1))
	{
		ft_sx(lst);
		((t_data *)((*lst)->content))->dist = 1;
	}
	tmp = *lst;
	while (tmp->next->next)
	{
		if ((((t_data *)tmp->next->content)->index
				== ((t_data *)tmp->next->next->content)->index + 1)
			|| (((t_data *)tmp->next->content)->index == min
				&& ((t_data *)tmp->next->next->content)->index == max))
			ft_sx_in(&tmp);
		tmp = tmp->next;
	}
}
