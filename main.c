/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:37:24 by kbelmajd          #+#    #+#             */
/*   Updated: 2025/05/16 12:37:31 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./execution/game.h"
#include "parsing/parsing.h"

int	main(int ac, char **av)
{
	t_my_game		game;
	t_data			data;
	t_cub			*cub;
	t_wall_textures	*texture;

	if (ac != 2 || HEIGHT <= 0 || WIDTH <= 0)
		return (perror("Error: Invalid arguments\n"), 1);
	cub = malloc(sizeof(t_cub));
	texture = malloc(sizeof(t_wall_textures));
	if (!texture || !cub)
		return (free(cub), 1);
	ft_memset(cub, 0, sizeof(t_cub));
	ft_memset(&data, 0, sizeof(t_data));
	if (proccess_input(&data, cub, av[1], texture))
		return (free_heap(cub), 1);
	ft_execution(&game, cub);
	return (0);
}
