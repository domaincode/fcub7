/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:11:03 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/16 10:33:36 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	draw_to_window(t_my_game *game)
{
	game_key_hook_confg(game, game->forward_steps, game->right_steps,
		game->rotation);
	check_intersections(game);
	mlx_put_image_to_window(game->co, game->win, game->img, 0, 0);
	return (0);
}

int	game_key_hook_press(int keycode, t_my_game *game)
{
	double	tmp;

	tmp = TILE_SIZE / 64;
	if (keycode == XK_Escape)
		free_game(game);
	else if (keycode == XK_a)
		game->right_steps = -tmp;
	else if (keycode == XK_d)
		game->right_steps = tmp;
	else if (keycode == XK_Left)
		game->rotation = -1;
	else if (keycode == XK_Right)
		game->rotation = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		game->forward_steps = -tmp;
	else if (keycode == XK_w || keycode == XK_Up)
		game->forward_steps = tmp;
	return (0);
}

int	game_key_hook_release(int keycode, t_my_game *game)
{
	if (keycode == XK_a)
		game->right_steps = 0;
	else if (keycode == XK_d)
		game->right_steps = 0;
	else if (keycode == XK_Left)
		game->rotation = 0;
	else if (keycode == XK_Right)
		game->rotation = 0;
	else if (keycode == XK_s || keycode == XK_Down)
		game->forward_steps = 0;
	else if (keycode == XK_w || keycode == XK_Up)
		game->forward_steps = 0;
	return (0);
}

void	ft_execution(t_my_game *game, t_cub *map)
{
	ft_copy(game, map);
	if (cub_init(game))
		return ;
	draw_to_window(game);
	mlx_key_hook(game->win, game_key_hook_release, game);
	mlx_hook(game->win, 2, KeyPressMask, game_key_hook_press, game);
	mlx_loop_hook(game->co, draw_to_window, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, free_game, game);
	mlx_loop(game->co);
}
