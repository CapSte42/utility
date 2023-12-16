/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_lin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:24:43 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_int(int *lis, int *parent)
{
	free(lis);
	free(parent);
}

static t_list	*ft_lis_lst(t_list *lst, int *parent, int max_index)
{
	t_list	*lis_lst;
	t_list	*node;
	size_t	*nmb;

	lis_lst = NULL;
	while (max_index >= 0)
	{
		nmb = malloc(sizeof(size_t));
		if (nmb == NULL)
		{
			ft_lstclear(&lis_lst, free);
			return (NULL);
		}
		*nmb = ft_lstto_nmb(lst, max_index);
		node = ft_lstnew(nmb);
		if (node == NULL)
		{
			free(nmb);
			ft_lstclear(&lis_lst, free);
			return (NULL);
		}
		ft_lstadd_front(&lis_lst, node);
		max_index = parent[max_index];
	}
	return (lis_lst);
}

static void	ft_lis_algrtm(t_list *lst, int n, int *lis, int *parent)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (ft_lstto_nmb(lst, i) > ft_lstto_nmb(lst, j)
				&& lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				parent[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	ft_lis_maxindex(int *lis, int n)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < n)
	{
		if (lis[max_index] <= lis[i])
		{
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

t_list	*ft_lis_lin(t_list *lst, int n, int *error)
{
	t_list	*lis_lst_lin;
	int		*lis;
	int		*parent;
	int		max_index;
	int		i;

	lis = malloc(sizeof(int) * n);
	parent = malloc(sizeof(int) * n);
	if (lis == NULL || parent == NULL)
	{
		*error = 2;
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		parent[i] = -1;
		i++;
	}
	ft_lis_algrtm(lst, n, lis, parent);
	max_index = ft_lis_maxindex(lis, n);
	lis_lst_lin = ft_lis_lst(lst, parent, max_index);
	ft_free_int(lis, parent);
	return (lis_lst_lin);
}
