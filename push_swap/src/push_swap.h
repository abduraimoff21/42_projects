/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:58:18 by dabdurai          #+#    #+#             */
/*   Updated: 2023/07/19 00:47:15 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int	*a;
	int	*b;
	int	*indexarray;
	int	topa;
	int	topb;
	int	bestindex;
	int	bestvalue;
	int	correctadd;
	int	correctvalue;
}	t_data;

void	push_to_a(t_data *data, int *x);
void	pushback(t_data *data);
void	push(t_data *data, int min, int max);
void	ft_push(t_data *data);
void	set_rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	free_args(t_data *data, char **args);
void	error(t_data *data);
void	initialize(t_data *data, char **argv);
void	double_check_arg(t_data *data, char *str);
void	ft_sort_three(t_data *data);
void	ft_sort_large(t_data *data);
void	ft_sort_small(t_data *data);
void	sortarray(t_data *data);
void	ft_free(t_data *data);
void	ft_check(t_data *data);

int		get_values(t_data *data);
int		ft_checkbestindex(t_data *data);
int		ft_find_correct_index_on_a(t_data *data, int index);
int		ft_moves(t_data *data, int i);
int		ft_atoi(t_data *data, char *str, char **args);
int		ft_is_sorted(t_data *data);
int		ft_is_duplicate(int *array, int maxindex);
int		ft_lowesta(t_data *data);

#endif