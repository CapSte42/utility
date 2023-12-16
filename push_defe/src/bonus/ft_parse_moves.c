/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:34:12 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 20:10:13 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_moves(char *moves)
{
	if (!ft_strncmp(moves, "sa\n", 3))
		return (1);
	else if (!ft_strncmp(moves, "sb\n", 3))
		return (2);
	else if (!ft_strncmp(moves, "ss\n", 3))
		return (3);
	else if (!ft_strncmp(moves, "pa\n", 3))
		return (4);
	else if (!ft_strncmp(moves, "pb\n", 3))
		return (5);
	else if (!ft_strncmp(moves, "ra\n", 3))
		return (6);
	else if (!ft_strncmp(moves, "rb\n", 3))
		return (7);
	else if (!ft_strncmp(moves, "rr\n", 3))
		return (8);
	else if (!ft_strncmp(moves, "rra\n", 4))
		return (9);
	else if (!ft_strncmp(moves, "rrb\n", 4))
		return (10);
	else if (!ft_strncmp(moves, "rrr\n", 4))
		return (11);
	else
		return (-1);
}

int	ft_do_scenario(int scenario, t_list **stack_a, t_list **stack_b)
{
	if (scenario == 1)
		return (ft_sx(stack_a));
	else if (scenario == 2)
		return (ft_sx(stack_b));
	else if (scenario == 3)
		return (ft_ss(stack_a, stack_b));
	else if (scenario == 4)
		return (ft_px(stack_a, stack_b));
	else if (scenario == 5)
		return (ft_px(stack_b, stack_a));
	else if (scenario == 6)
		return (ft_rx(stack_a));
	else if (scenario == 7)
		return (ft_rx(stack_b));
	else if (scenario == 8)
		return (ft_rr(stack_a, stack_b));
	else if (scenario == 9)
		return (ft_rrx(stack_a));
	else if (scenario == 10)
		return (ft_rrx(stack_b));
	else if (scenario == 11)
		return (ft_rrr(stack_a, stack_b));
	return (0);
}

int	ft_parse_moves(t_list **stack_a, t_list **stack_b)
{
	int		scenario;
	int		illegal_moves;
	char	*moves;

	scenario = 0;
	illegal_moves = 0;
	while (scenario != -1)
	{
		moves = ft_get_next_line(0);
		if (moves == NULL)
			break ;
		scenario = ft_check_moves(moves);
		illegal_moves += ft_do_scenario(scenario, stack_a, stack_b);
		free(moves);
	}
	if (scenario == -1)
		illegal_moves = -1;
	return (illegal_moves);
}
