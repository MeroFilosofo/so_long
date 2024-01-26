/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:44:38 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/26 16:47:09 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(t_game *game)
{
	size_t	i;

	if (!game->map)
		return ;
	i = -1;
	while (++i < game->map_height)
	{
		free(game->map[i]);
		free(game->map_filled[i]);
	}
	free(game->map);
	free(game->map_filled);
}

int	fill_map(t_game *game, char *map)
{
	int		fd;
	size_t	i;
	size_t	j;

	game->map = malloc(sizeof(char *) * game->map_height);
	game->map_filled = malloc(sizeof(char *) * game->map_height);
	if (!game->map || !game->map_filled)
		return (ft_printf("Error\nNo se pudo reservar memoria x mapa\n"), 0);
	fd = open(map, O_RDONLY);
	i = -1;
	while (++i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		game->map_filled[i] = ft_strdup(game->map[i]);
		if (i == 0 || i == game->map_height - 1)
		{
			j = -1;
			while (++j < game->map_width)
				if (game->map[i][j] != '1')
					return (game->map_height = ++i, p_error(5), 0);
		}
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (game->map_height = ++i, p_error(5), 0);
	}
	return (close(fd), 1);
}

int	floodfill(t_game *game, size_t x, size_t y, t_test *test)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (0);
	if (game->map[y][x] == '1' || game->map_filled[y][x] == 'x')
		return (0);
	if (game->map[y][x] == '0')
		game->map_filled[y][x] = 'x';
	if (game->map[y][x] == 'C')
	{
		game->map_filled[y][x] = 'x';
		test->collect--;
	}
	if (game->map[y][x] == 'E')
	{
		game->map_filled[y][x] = 'x';
		test->exit--;
	}
	floodfill(game, x + 1, y, test);
	floodfill(game, x - 1, y, test);
	floodfill(game, x, y + 1, test);
	floodfill(game, x, y - 1, test);
	return (0);
}

int	test_fill(t_game *game, t_test *test)
{
	if (game->map_filled[game->map_height - 1][game->map_width] == '\n'
		||game->map_filled[game->map_height - 1][game->map_width] == '\r')
		return (ft_printf("Error\nEl mapa tiene una linea vacia alfinal\n"),
			0);
	floodfill(game, game->x_pos, game->y_pos, test);
	if (test->collect != 0)
		return (ft_printf("Error\nEs imposible comerse todos los cocos\n"), 0);
	if (test->exit != 0)
		return (ft_printf("Error\nEs imposible llegar a la salida\n"), 0);
	return (1);
}
