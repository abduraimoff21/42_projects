/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:56:52 by dabdurai          #+#    #+#             */
/*   Updated: 2023/02/15 01:40:25 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lowesta(t_data *data)
{
	int	i;
	int	lowest;
	int	lowestindex;

	i = 0;
	lowestindex = i;
	lowest = data->a[i];
	while (i <= data->topa)
	{
		if (data->a[i] < lowest)
		{
			lowest = data->a[i];
			lowestindex = i;
		}
		i++;
	}
	return (lowestindex);
}

void	ft_free(t_data *data)
{
	free(data->a);
	data->a = NULL;
	free(data->b);
	data->b = NULL;
	free(data->indexarray);
	data->indexarray = NULL;
}

void	sortarray(t_data *data)
{
	int	n;
	int	i;
	int	j;
	int	tmp;

	n = data->topa + 1;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (data->indexarray[j] > data->indexarray[i])
			{
				tmp = data->indexarray[i];
				data->indexarray[i] = data->indexarray[j];
				data->indexarray[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_is_duplicate(int *array, int maxindex)
{
	int	i;
	int	j;

	i = 0;
	while (i <= maxindex)
	{
		j = i + 1;
		while (j <= maxindex)
		{
			if (array[j] == array[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
