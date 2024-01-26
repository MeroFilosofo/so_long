/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:09:06 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/26 16:39:38 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	p_error(int error)
{
	if (error == 1)
		ft_printf("Error\nEl primer parametro tiene que ser"
			" el nombre de un mapa y no haber mas parámetros\n");
	else if (error == 2)
		ft_printf("Error\nEl mapa no tiene extension .ber\n");
	else if (error == 3)
		ft_printf("Error\nMapa con linea vacia\n");
	else if (error == 4)
		ft_printf("Error\nMapa no rectangular\n");
	else if (error == 5)
		ft_printf("Error\nEl mapa no esta cerrado\n");
	else
		ft_printf("Error\n");
}

int	on_close(t_game *game)
{
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_textures(game);
	free(game->mlx);
	free_map(game);
	free(game);
	exit(0);
	return (0);
}

int	init(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->sprite_size
			* game->map_width, game->sprite_size * game->map_height,
			"Come-Cocos");
	mlx_hook(game->window, 17, 0, on_close, game);
	mlx_key_hook(game->window, key_hook, game);
	game->moves = 0;
	return (0);
}

int	test_map_extension(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r' || map[len - 2] != 'e' || map[len - 3] != 'b'
		|| map[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (p_error(1), 1);
	if (!test_map_extension(argv[1]))
		return (p_error(2), 0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->map_height = 0;
	game->map = NULL;
	if (!load_map(game, argv[1]))
	{
		free_map(game);
		free(game);
		return (1);
	}
	game->mlx = mlx_init();
	load_textures(game);
	init(game);
	map_paint(game);
	paint_player(game);
	mlx_loop(game->mlx);
	return (0);
}
