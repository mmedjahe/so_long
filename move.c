/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:15:49 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/07 01:46:55 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 
void ft_collectibles(t_map *game, int y, int x)
{
	if(game->map[y][x] == COLLECTIBLES)
	{
		game->collectibles_left--;
		game->map[y][x] = FLOOR;
	}
}

void move_map(t_map *game, int y, int x)
{
	if (game->map[y][x] == MAP_EXIT && game->collectibles_left == 0)
	{
		valid_msg("GG");
		close_game(game);
	}
	else if (game->map[y][x] == COLLECTIBLES)
		ft_collectibles(game, y, x);
	else if (game->map[y][x] == WALL)
		return;
	game->player_y = y;
	game->player_x = x;
	game->map[y][x] = FLOOR;
	game->steps++;
	game->map[game->player_y][game->player_x] = PLAYER;
}
void want_move(t_map *game, int touch)
{
	if (touch == W)
		move_map(game, game->player_y +1, game->player_x);
	if (touch == A)
		move_map(game, game->player_y, game->player_x -1);
	if (touch == S)
		move_map(game, game->player_y -1, game->player_x);
	if (touch == D)
		move_map(game, game->player_y , game->player_x +1);
	if (touch == ESC)
		close_game(game);
}