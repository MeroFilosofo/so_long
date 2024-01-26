/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:22:55 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/23 15:40:46 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W || keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move(game, keycode);
	else if (keycode == KEY_ESC)
		on_close(game);
	return (0);
}

int	move(t_game *game, int keycode)
{
	int	moved;

	moved = 0;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		moved = move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moved = move_player(game, 1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moved = move_player(game, 0, 1);
	else if (keycode == KEY_W || keycode == KEY_UP)
		moved = move_player(game, 0, -1);
	map_paint(game);
	paint_player(game);
	print_info(game, moved);
	if (game->collectibles == 0 && game->map[game->y_pos][game->x_pos] == 'E')
		on_close(game);
	return (0);
}

int	move_player(t_game *game, int x, int y)
{
	if (game->map[y + game->y_pos][x + game->x_pos] == '1')
		return (0);
	if (game->map[y + game->y_pos][x + game->x_pos] == 'C')
	{
		game->map[y + game->y_pos][x + game->x_pos] = '0';
		game->collectibles--;
	}
	game->moves++;
	game->x_pos += x;
	game->y_pos += y;
	return (1);
}
