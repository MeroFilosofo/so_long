/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivromero <ivromero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:34:59 by ivromero          #+#    #+#             */
/*   Updated: 2024/01/26 18:55:44 by ivromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

typedef struct s_test
{
	int	player;
	int	exit;
	int	collect;
}			t_test;

typedef struct s_game
{
	char		**map;
	char		**map_filled;
	void		*mlx;
	void		*window;

	void		*wall;
	void		*floor;
	void		*collect;
	void		*exit;
	void		*player;

	size_t		sprite_size;
	size_t		map_width;
	size_t		map_height;
	size_t		collectibles;
	size_t		player_offset;
	size_t		collect_offset;
	size_t		exit_offset;
	size_t		x_pos;
	size_t		y_pos;
	size_t		moves;
}			t_game;

int		key_hook(int keycode, t_game *game);
int		on_close(t_game *game);
int		move_player(t_game *game, int x, int y);
int		init(t_game *game);
int		move(t_game *game, int keycode);
void	print_info(t_game *game, int moved);
void	paint_player(t_game *game);
int		fill_map(t_game *game, char *map);
void	free_textures(t_game *game);
void	free_map(t_game *game);
void	p_error(int error);

size_t	ft_maplinelen(const char *s);
int		load_map(t_game *game, char *map);
int		elements_map(t_game *game, t_test *test);
int		test_items(t_game *game, t_test *test);
int		floodfill(t_game *game, size_t x, size_t y, t_test *test);
int		*char_position(t_game *game, char c);
int		test_fill(t_game *game, t_test *test);
int		load_textures(t_game *game);
void	map_paint(t_game *game);

#endif
