/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:51 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lis_build(t_list *node, t_list **lst, int *error)
{
	t_list	*lis_lst;
	t_list	*lis_lst_crcl;

	error = 0;
	lis_lst = ft_lis_lin(node, ft_lstsize(node), error);
	if (lis_lst == NULL)
		return (NULL);
	lis_lst_crcl = ft_lis_crcl(lis_lst, *lst, error);
	if (error != 0)
	{
		ft_lstclear(&lis_lst, free);
		return (NULL);
	}
	if (lis_lst_crcl != NULL)
	{
		ft_lstadd_front(&lis_lst, ft_lstlast(lis_lst_crcl));
		lis_lst = lis_lst_crcl;
	}
	return (lis_lst);
}

static t_list	*ft_lis_build_re(t_list **lst, t_list **lis_lst,
					t_list *node, int *error)
{
	t_list	*lis_lst_re;

	lis_lst_re = NULL;
	lis_lst_re = ft_lis_build(node, lst, error);
	if (lis_lst_re == NULL)
	{
		if (*error == 0)
			*error = 4;
		ft_lstclear(lis_lst, free);
		return (NULL);
	}
	else if (ft_lstsize(lis_lst_re) > ft_lstsize(*lis_lst))
	{
		ft_lstclear(lis_lst, free);
		*lis_lst = lis_lst_re;
	}
	else
		ft_lstclear(&lis_lst_re, free);
	return (*lis_lst);
}

t_list	*ft_lis(t_list **lst)
{
	t_list	*lis_lst;
	t_list	*node;
	size_t	min_lis;
	int		error;

	lis_lst = NULL;
	node = *lst;
	min_lis = 2147483647;
	error = 0;
	while (node != NULL)
	{
		if (min_lis >= ((t_data *) node->content)->index)
		{
			lis_lst = ft_lis_build_re(lst, &lis_lst, node, &error);
			if (lis_lst == NULL)
				ft_error(error, NULL, lst);
		}
		min_lis = ft_min_index(lis_lst, (size_t) ft_lstsize(*lst));
		node = node->next;
	}
	return (lis_lst);
}
