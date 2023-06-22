/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdurai <dabdurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:25:18 by dabdurai          #+#    #+#             */
/*   Updated: 2023/02/23 03:30:24 by dabdurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 32, height * 32);
	game->playersecond = height;
	game->playerfirst = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 32, height * 32);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"images/pokemon.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/ring1.xpm", &i, &j);
}

void	add_in_graphics_condition(t_complete *game, int width, int height)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 32, height * 32);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 32, height * 32);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 32, height * 32);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			add_in_graphics_condition(game, width, height);
			width++;
		}
		height++;
	}
}
