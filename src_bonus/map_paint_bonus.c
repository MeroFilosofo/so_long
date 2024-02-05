/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:28:08 by ivromero          #+#    #+#             */
/*   Updated: 2024/02/05 12:15:52 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	paint_player(t_game *game)
{
	size_t	frame_offset;
	size_t	x_offset;
	size_t	y_offset;

	x_offset = 0;
	y_offset = 0;
	frame_offset = game->sprite_size - ((game->sprite_size / 4)
			* game->player_frame++);
	if (game->player_direction == 0)
		y_offset = frame_offset;
	if (game->player_direction == 1)
		x_offset = -frame_offset;
	if (game->player_direction == 3)
		x_offset = frame_offset;
	if (game->player_direction == 2)
		y_offset = -frame_offset;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player[game->player_direction][game->player_sprite++],
		game->x_pos * game->sprite_size + game->player_offset + x_offset,
		game->y_pos * game->sprite_size + game->player_offset + y_offset);
	if (game->player_sprite == 4)
		game->player_sprite = 0;
	if (game->player_frame == 5)
		game->player_frame = 4;
}

void	print_info(t_game *game, int moved)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", moves);
	mlx_string_put(game->mlx, game->window, 16, 32, 0x00FFFFFF, str);
	free(str);
	free(moves);
	if (moved)
		ft_printf("Moves: %d\n", game->moves);
}

void	paint_element(t_game *game, int x, int y)
{
	int		offset;
	void	*sprite;

	offset = 0;
	if (game->map[y][x] == '1')
		sprite = game->wall;
	if (game->map[y][x] == 'C')
		sprite = game->collect;
	if (game->map[y][x] == 'C')
		offset = game->collect_offset;
	if (game->map[y][x] == '0')
		sprite = game->floor;
	if (game->map[y][x] == 'E')
		sprite = game->exit;
	if (game->map[y][x] == 'E' && game->collectibles == 0)
		sprite = game->exit_open;
	if (game->map[y][x] == 'E')
		offset = game->exit_offset;
	if (game->map[y][x] == 'B')
	{
		sprite = game->enemy;
		offset = game->enemy_offset;
	}
	mlx_put_image_to_window(game->mlx, game->window, sprite, x
		* game->sprite_size + offset, y * game->sprite_size + offset);
}

void	map_paint(t_game *g)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < g->map_height)
	{
		j = -1;
		while (++j < g->map_width)
			paint_element(g, j, i);
	}
}

int	update_screen(t_game *game)
{
	if (++game->frames % 1000 == 0)
	{
		map_paint(game);
		paint_player(game);
		print_info(game, 0);
		if (game->frames % 4000 == 0)
			random_move_enemy(game);
	}
	if (game->frames == 1000000)
		game->frames = 0;
	return (0);
}
