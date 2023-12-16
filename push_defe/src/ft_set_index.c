/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:25 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:30:35 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(ssize_t *a, ssize_t *b)
{
	ssize_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_quick_sort(ssize_t *array_s, ssize_t start, ssize_t end)
{
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (array_s[i] <= array_s[pivot] && i < end)
				i++;
			while (array_s[j] > array_s[pivot])
				j--;
			if (i < j)
				ft_swap(&array_s[i], &array_s[j]);
		}
		ft_swap(&array_s[pivot], &array_s[j]);
		ft_quick_sort(array_s, start, j - 1);
		ft_quick_sort(array_s, j + 1, end);
	}
}

static ssize_t	*ft_fill_array(t_list **lst)
{
	ssize_t	i;
	t_list	*tmp;
	ssize_t	*array_s;

	tmp = *lst;
	array_s = malloc(sizeof(ssize_t) * ft_lstsize(*lst));
	if (!array_s)
		return (NULL);
	i = -1;
	while (tmp)
	{
		array_s[++i] = ((t_data *)tmp->content)->value;
		tmp = tmp->next;
	}
	return (array_s);
}

void	ft_set_index(t_list **lst)
{
	ssize_t	*array_s;
	ssize_t	i;
	ssize_t	j;
	t_list	*tmp;

	tmp = *lst;
	array_s = ft_fill_array(lst);
	if (!array_s)
		ft_error(2, NULL, lst);
	ft_quick_sort(array_s, 0, ft_lstsize(*lst) - 1);
	tmp = *lst;
	i = ft_lstsize(*lst);
	while (tmp)
	{
		j = -1;
		while (++j < i)
			if (((t_data *)tmp->content)->value == array_s[j])
				((t_data *)tmp->content)->index = j + 1;
		tmp = tmp->next;
	}
	free(array_s);
}
