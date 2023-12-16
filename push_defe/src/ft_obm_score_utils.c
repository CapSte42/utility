/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obm_score_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:28:29 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_bggr(ssize_t a, ssize_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

ssize_t	ft_smllr(ssize_t a, ssize_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_mod(ssize_t a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
