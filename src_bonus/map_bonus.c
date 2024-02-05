/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:29:01 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/29 15:10:07 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

size_t	ft_maplinelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\r' && s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int	test_items(t_game *game, t_test *test)
{
	if (game->map_height < 2 || game->map_width < 2)
		return (ft_printf("Error\nEl mapa es demasiado pequeño %zux%zu\n",
				game->map_height, game->map_width), 0);
	if (game->map_height > 100 || game->map_width > 100)
		return (ft_printf("Error\nEl mapa es demasiado grande en pantalla\n"),
			0);
	if (test->player != 1)
		return (ft_printf("Error\nEl mapa tiene que tener un jugador\n"), 0);
	if (test->exit != 1)
		return (ft_printf("Error\nEl mapa tiene que tener una salida\n"), 0);
	if (test->collect < 1)
		return (ft_printf("Error\nNo hay coleccionables\n"), 0);
	return (1);
}

int	elements_map(t_game *game, t_test *test)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (!ft_strrchr("10CPEB", game->map[i][j]))
				return (ft_printf("Error\nCaracteres no validos\n"), 0);
			if (game->map[i][j] == 'P')
			{
				test->player++;
				game->x_pos = j;
				game->y_pos = i;
				game->map[i][j] = '0';
			}
			if (game->map[i][j] == 'E')
				test->exit++;
			if (game->map[i][j] == 'C')
				test->collect++;
		}
	}
	return (game->collectibles = test->collect, 1);
}

t_test	*init_test(void)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	test->player = 0;
	test->exit = 0;
	test->collect = 0;
	return (test);
}

int	load_map(t_game *game, char *map)
{
	int		fd;
	char	*line;
	t_test	*test;

	test = init_test();
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nEl mapa no existe\n"), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), free(test), ft_printf("Error\nEl mapa vacio\n"), 0);
	game->map_width = ft_maplinelen(line);
	while (line)
	{
		if (ft_maplinelen(line) == 0 || game->map_width == 0)
			return (close(fd), free(line), free(test), p_error(3), 0);
		if (game->map_height++ > 1 && game->map_width != ft_maplinelen(line))
			return (close(fd), free(line), free(test), p_error(4), 0);
		free(line);
		line = get_next_line(fd);
	}
	if (!fill_map(game, map) || !elements_map(game, test)
		|| !test_items(game, test) || !test_fill(game, test))
		return (close(fd), free(test), 0);
	return (close(fd), free(test), 1);
}
