/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlane <cadlane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:03:50 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/16 10:36:48 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	check_free(void *ptr, t_my_game *game)
{
	if (ptr != NULL)
		mlx_destroy_image(game->co, ptr);
}

int	free_game(t_my_game *game)
{
	check_free(game->img, game);
	check_free(game->map_img, game);
	check_free(game->north, game);
	check_free(game->south, game);
	check_free(game->west, game);
	check_free(game->east, game);
	if (game->win)
		mlx_destroy_window(game->co, game->win);
	mlx_destroy_display(game->co);
	free(game->co);
	free_all(game->parsing);
	return (0);
}
