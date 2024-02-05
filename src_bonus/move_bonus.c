/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:22:55 by ivromero          #+#    #+#             */
/*   Updated: 2024/02/05 12:02:43 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player_frame != 4)
		return (0);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		moved = move_player(game, -1, 0, 3);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moved = move_player(game, 1, 0, 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moved = move_player(game, 0, 1, 2);
	else if (keycode == KEY_W || keycode == KEY_UP)
		moved = move_player(game, 0, -1, 0);
	else if (keycode == KEY_ESC)
		on_close(game);
	print_info(game, moved);
	if (game->collectibles == 0 && game->map[game->y_pos][game->x_pos] == 'E')
		on_close(game);
	if (game->map[game->y_pos][game->x_pos] == 'B')
	{
		ft_printf("You lose\n");
		on_close(game);
	}
	return (0);
}

//direction 0 up, 1 right 2 down, 3 left,
int	move_player(t_game *game, int x, int y, int direction)
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
	game->player_frame = 0;
	game->player_direction = direction;
	system("afplay -r 0 ./sounds/wakawaka.mp3 &");
	return (1);
}

void	random_move_enemy(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'B')
				move_enemy(game, x, y, rand() % 4);
			x++;
		}
		y++;
	}
	if (game->map[game->y_pos][game->x_pos] == 'B')
		on_close(game);
}

//direction 0 up, 1 down, 2 left, 3 right
void	move_enemy(t_game *game, size_t x, size_t y, size_t direction)
{
	if (direction == 0 && y > 0 && !ft_strrchr("1CEB", game->map[y - 1][x]))
	{
		game->map[y - 1][x] = 'B';
		game->map[y][x] = '0';
	}
	else if (direction == 1 && y < game->map_height - 1 && !ft_strrchr("1CEB",
			game->map[y + 1][x]))
	{
		game->map[y + 1][x] = 'B';
		game->map[y][x] = '0';
	}
	else if (direction == 2 && x > 0 && !ft_strrchr("1CEB", game->map[y][x
			- 1]))
	{
		game->map[y][x - 1] = 'B';
		game->map[y][x] = '0';
	}
	else if (direction == 3 && x < game->map_width - 1 && !ft_strrchr("1CEB",
			game->map[y][x + 1]))
	{
		game->map[y][x + 1] = 'B';
		game->map[y][x] = '0';
	}
}
