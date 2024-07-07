/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:15:56 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/07 01:16:29 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(t_map *game, char **map, int y, int x)
{
	if (map[y][x] == WALL)
		return;
	if (map[y][x] == COLLECTIBLES)
		{
			game->flood_collect++;
			map[y][x] = WALL;
		}
	else if(map[y][x] == MAP_EXIT)
		game->flood_exit++;
	flood_fill(game, map, y -1, x);
	flood_fill(game, map, y +1, x);
	flood_fill(game, map, y, x -1);
	flood_fill(game, map, y, x + 1);
}
void loc_player(t_map *game)
{
	int i;
	int j;
	char **new_map;
	
	i = 0;
	j = 0;

	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
			{
				if(game->map[i][j] == PLAYER)
					{
						game->player_y = i;
						game->player_x = j;
						break;
					}
				j++;
			}
		i++;
	}
	new_map = ft_cpy(game->map);
	flood_fill(game, new_map, game->player_y, game->player_x);
	free_cpy(new_map);
}
 char	**ft_cpy(char **map)
{
	char	**new;
	int		i;

;
	i = 0;
	new = malloc(sizeof(char *) * ( (check_map_height(map) + 1)));
	if (!new)
		return (NULL);
	while (new[i])
	{
		new[i] = ft_strdup(map[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void free_cpy(char **map)
{
	int i;

	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void ft_flood(t_map *game)
{
	if(game->collectibles == game->flood_collect && game->flood_exit == game->exit)
		valid_msg("successful floodfill");
	else 
		error_exit(game, "floodfill error");
}
