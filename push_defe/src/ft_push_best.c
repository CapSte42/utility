/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:00 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_negative_dist(t_list **stack_a, t_list **stack_b,
	t_list *node, char *moves)
{
	ssize_t	dist_a;
	ssize_t	dist_b;

	dist_a = ((t_data *)node->content)->obm->dist;
	dist_b = ((t_data *)node->content)->dist;
	while (dist_b < 0 && dist_a < 0 && moves != NULL)
	{
		ft_rrr(stack_a, stack_b);
		moves = ft_strjoin(moves, "rrr\n");
		dist_b++;
		dist_a++;
	}
	while (dist_a < 0 && moves != NULL)
	{
		ft_rrx(stack_a);
		moves = ft_strjoin(moves, "rra\n");
		dist_a++;
	}
	while (dist_b < 0 && moves != NULL)
	{
		ft_rrx(stack_b);
		moves = ft_strjoin(moves, "rrb\n");
		dist_b++;
	}
	return (moves);
}

static char	*ft_positive_dist(t_list **stack_a, t_list **stack_b,
	t_list *node, char *moves)
{
	ssize_t	dist_a;
	ssize_t	dist_b;

	dist_a = ((t_data *)node->content)->obm->dist;
	dist_b = ((t_data *)node->content)->dist;
	while (dist_b > 0 && dist_a > 0 && moves != NULL)
	{
		ft_rr(stack_a, stack_b);
		moves = ft_strjoin(moves, "rr\n");
		dist_b--;
		dist_a--;
	}
	while (dist_a > 0 && moves != NULL)
	{
		ft_rx(stack_a);
		moves = ft_strjoin(moves, "ra\n");
		dist_a--;
	}
	while (dist_b > 0 && moves != NULL)
	{
		ft_rx(stack_b);
		moves = ft_strjoin(moves, "rb\n");
		dist_b--;
	}
	return (moves);
}

char	*ft_push_best(t_list **stack_a, t_list **stack_b,
	t_list *node, char *moves)
{
	if (moves != NULL)
		moves = ft_positive_dist(stack_a, stack_b, node, moves);
	if (moves != NULL)
		moves = ft_negative_dist(stack_a, stack_b, node, moves);
	if (moves != NULL)
	{
		ft_px(stack_a, stack_b);
		moves = ft_strjoin(moves, "pa\n");
	}
	return (moves);
}
