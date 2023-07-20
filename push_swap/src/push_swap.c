/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:58:15 by dabdurai          #+#    #+#             */
/*   Updated: 2023/07/18 23:39:07 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_data *data, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
		i++;
	data->indexarray = (int *)malloc(sizeof(int) * i);
	data->a = (int *)malloc(sizeof(int) * i);
	data->b = (int *)malloc(sizeof(int) * i);
	if (!data->indexarray || !data->a
		|| !data->b)
		error(data);
	j = 0;
	i--;
	while (i >= 0)
	{
		data->indexarray[j] = ft_atoi(data, argv[i], argv);
		data->a[j++] = ft_atoi(data, argv[i--], argv);
	}
	data->topa = j - 1;
	data->topb = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	char	*str;		
	int		flag;

	str = "";
	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	flag = 0;
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i], flag);
		flag = 1;
		i++;
	}
	double_check_arg(&data, str);
	ft_check(&data);
	return (0);
}