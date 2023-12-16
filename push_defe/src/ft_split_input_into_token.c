/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input_into_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:16 by smontuor          #+#    #+#             */
/*   Updated: 2023/12/12 19:17:53 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_one_arg(char *str, char sep)
{
	char	**token;
	int		i;

	sep = ' ';
	token = ft_split(str, sep);
	if (token == NULL)
		ft_error(0, NULL, NULL);
	i = 0;
	return (token);
}

static void	ft_multiple_arg_is_triky(char **token)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == ' ')
			{
				ft_error(1, token, NULL);
			}
			j++;
		}
		i++;
	}
}

static char	**ft_multiple_arg(char **matrix, int size)
{
	char	**token;
	int		i;

	i = 1;
	token = malloc(size * sizeof(char *));
	if (token == NULL)
		ft_error(2, NULL, NULL);
	while (i < size)
	{
		token[i - 1] = ft_strdup(matrix[i]);
		if (token[i - 1] == NULL)
			ft_error(2, token, NULL);
		i++;
	}
	token[size - 1] = NULL;
	ft_multiple_arg_is_triky(token);
	i = 0;
	return (token);
}

char	**ft_split_input_into_token(int ac, char **av)
{
	char	**token;

	token = NULL;
	if (ac < 2)
	{
		ft_error(0, NULL, NULL);
	}
	else if (ac == 2)
	{
		token = ft_one_arg(av[1], ' ');
	}
	else if (ac > 2)
	{
		token = ft_multiple_arg(av, ac);
	}
	return (token);
}
