/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:14 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_all(t_list **stack_a, t_list **stack_b, t_list **lis)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	ft_lstclear(lis, free);
}

static int	ft_if_swapswap(t_list *stack_a, t_list *lis)
{
	if ((((t_data *)((stack_a)->next->content))->index
		!= (*(size_t *)lis->content))
		&& ((t_data *)((stack_a)->next->content))->dist != 1)
		return (1);
	else
		return (0);
}

static char	*ft_remove_ra(t_list **stack_a, char *moves)
{
	char	*new;
	char	**split;
	int		size;
	int		cont;

	split = ft_split(moves, '\n');
	size = 0;
	while (split[size])
		size++;
	while (size != 0 && split[size - 1][0] == 'r' && split[size - 1][1] == 'a')
	{
		ft_rrx(stack_a);
		size--;
	}
	new = ft_calloc(((size + 1) * 2), sizeof(char));
	cont = -1;
	while (++cont < size)
	{
		new = ft_strjoin(new, split[cont]);
		new = ft_strjoin(new, "\n");
	}
	free(moves);
	ft_free_matrix(split);
	return (new);
}

static char	*ft_set_stacks(t_list **stack_a, t_list **stack_b,
		t_list *lis, char *moves)
{
	int		i;

	i = ft_lstsize(*stack_a);
	while (moves && --i >= 0)
	{
		if (((t_data *)((*stack_a)->content))->dist == 1)
			moves = ft_strjoin(moves, "sa\n");
		if (((t_data *)((*stack_a)->content))->index
			== (*(size_t *)lis->content) && moves != NULL)
		{
			ft_rx(stack_a);
			moves = ft_strjoin(moves, "ra\n");
			if (lis->next)
				lis = lis->next;
		}
		else if (((t_data *)((*stack_a)->content))->index
			!= (*(size_t *)lis->content) && moves != NULL)
		{
			if (ft_if_swapswap(*stack_a, lis) == 1 && i > 0)
				moves = ft_swapswap(stack_a, stack_b, moves);
			ft_px(stack_b, stack_a);
			moves = ft_strjoin(moves, "pb\n");
		}
	}
	return (moves);
}

char	*ft_push_swap(t_list **stack_a, t_list *lis)
{
	t_list	*stack_b;
	t_list	*obm;
	char	*moves;

	stack_b = NULL;
	moves = ft_calloc(1, sizeof(char));
	if (moves != NULL)
		moves = ft_set_stacks(stack_a, &stack_b, lis, moves);
	if (moves != NULL)
		moves = ft_remove_ra(stack_a, moves);
	while (stack_b && moves != NULL)
	{
		ft_set_obm_distb(stack_a, &stack_b);
		obm = ft_obm_score(stack_b);
		moves = ft_push_best(stack_a, &stack_b, obm, moves);
	}
	if (moves != NULL)
		moves = ft_last_rotate(stack_a, moves);
	if (moves == NULL)
	{
		ft_free_all(stack_a, &stack_b, &lis);
		ft_error(4, NULL, NULL);
	}
	ft_free_all(stack_a, &stack_b, &lis);
	return (moves);
}
