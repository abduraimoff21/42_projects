/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:25:46 by dabdurai          #+#    #+#             */
/*   Updated: 2023/05/14 03:56:53 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	right_move(t_complete *game, int i, int j);

int	movement_validate(t_complete *game, int i, int j, int movement)
{
	int	k;

	if (movement == 1 || movement == 125)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	if (movement == 2 || movement == 124)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->playerfirst;
	j = game->playersecond;
	if (movement == 0 || movement == 123)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	movement_validate(game, i, j, movement);
	return (1);
}

static	int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->playerfirst;
	j = game->playersecond;
	if (movement == 13 || movement == 126)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	movement_validate(game, i, j, movement);
	return (1);
}

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\e[31m\e[1m\nYou Have Won, Congrats! \e[0m \n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->playerfirst = i;
		game->playersecond = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13 || command == 126)
		works = keyboard_w_s(game, command);
	if (command == 1 || command == 125)
		works = keyboard_w_s(game, command);
	if (command == 0 || command == 123)
		works = keyboard_a_d(game, command);
	if (command == 2 || command == 124)
		works = keyboard_a_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
