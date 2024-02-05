/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:03:30 by ivromero          #+#    #+#             */
/*   Updated: 2024/02/05 12:34:23 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	load_player_textures(t_game *g)
{
	int		w;
	int		h;
	size_t	i;
	size_t	j;
	char	*path;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			path = ft_strjoinfree(ft_strjoinfree(ft_strdup("textures/p/"),
						ft_strjoinfree(ft_itoa(i), ft_itoa(j))),
					ft_strdup(".xpm"));
			g->player[i][j] = mlx_xpm_file_to_image(g->mlx, path, &w, &h);
			free(path);
			j++;
		}
		i++;
	}
	return (0);
}

int	load_textures(t_game *g)
{
	int	w;
	int	h;

	load_player_textures(g);
	g->wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	g->sprite_size = w;
	g->enemy = mlx_xpm_file_to_image(g->mlx, "textures/ghost.xpm", &w, &h);
	g->enemy_offset = (g->sprite_size - w) / 2;
	g->player_offset = (g->sprite_size - w) / 2;
	g->floor = mlx_xpm_file_to_image(g->mlx, "./textures/floor.xpm", &w, &h);
	g->collect = mlx_xpm_file_to_image(g->mlx, "textures/cerebro.xpm", &w, &h);
	g->collect_offset = (g->sprite_size - w) / 2;
	g->exit = mlx_xpm_file_to_image(g->mlx, "./textures/door.xpm", &w, &h);
	g->exit_open = mlx_xpm_file_to_image(g->mlx, "./textures/door_open.xpm", &w,
			&h);
	g->exit_offset = (g->sprite_size - w) / 2;
	return (0);
}

void	free_textures(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mlx_destroy_image(game->mlx, game->player[i][j]);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->exit_open);
}
