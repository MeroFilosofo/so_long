/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:28:08 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/26 18:57:43 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width,
			&height);
	game->sprite_size = width;
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/zombie.xpm",
			&width, &height);
	game->player_offset = (game->sprite_size - width) / 2;
	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&width, &height);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/cerebro.xpm",
			&width, &height);
	game->collect_offset = (game->sprite_size - width) / 2;
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm", &width,
			&height);
	game->exit_offset = (game->sprite_size - width) / 2;
	return (0);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
}

void	paint_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->player, game->x_pos
		* game->sprite_size + game->player_offset, game->y_pos
		* game->sprite_size + game->player_offset);
}

void	print_info(t_game *game, int moved)
{
	if (moved)
		ft_printf("Moves: %d\n", game->moves);
}

void	map_paint(t_game *g)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = g->sprite_size;
	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (++j < g->map_width)
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->window, g->wall, j * size, i
					* size);
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->window, g->collect, j * size
					+ g->collect_offset, i * size + g->collect_offset);
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->window, g->floor, j * size, i
					* size);
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->window, g->exit, j * size
					+ g->exit_offset, i * size + g->exit_offset);
		}
	}
}
