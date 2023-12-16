/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obm_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:42 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_calc_score(t_data *content)
{
	size_t	score;

	if (content->dist >= 0 && content->obm->dist >= 0)
		score = ft_bggr(content->dist, content->obm->dist);
	else if (content->dist < 0 && content->obm->dist < 0)
		score = ft_mod(ft_smllr(content->dist, content->obm->dist));
	else if (content->dist >= 0 && content->obm->dist < 0)
		score = content->dist + ft_mod(content->obm->dist);
	else if (content->dist < 0 && content->obm->dist >= 0)
		score = ft_mod(content->dist) + content->obm->dist;
	else
		score = 0;
	return (score);
}

t_list	*ft_obm_score(t_list *stack_b)
{
	t_list	*node;
	size_t	score;

	score = 251;
	node = NULL;
	while (stack_b != NULL)
	{
		if (score > ft_calc_score((t_data *)stack_b->content))
		{
			score = ft_calc_score((t_data *)stack_b->content);
			node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (node);
}
