/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:31:20 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/05 00:42:20 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_map *game)
{
	int i;
	int j;
	int firstline;
	
	i =0;
	j=0;
	
	if(!game->map || game->height == 0)
		return error_exit(game, "map isn't valid");
	firstline = ft_strlen(game->map[i]);
	i++;
	while(game->map[i])
	{
		j =  ft_strlen(game->map[i]);
		if(firstline != j)
			return error_exit(game, "map isn't valid");
		i++;
	}
}
void	full_wall(t_map *game)
{
	int i;
	int j;

	i =0;
	j=0;
	while(game->map[i][j])
	{
		if(game->map[i][j] != WALL)
			return error_exit(game, "map isn't valid");
		j++;
	}
	while(game->map[i])
	{
		if(game->map[i][0] != WALL)
			return error_exit(game, "map isn't valid");
		i++;
	}
	j =0;
	while(game->map[i][j])
	{
		if(game->map[i][j] != WALL)
			return error_exit(game, "map isn't valid");
		j++;
	}
	i =0;
	while(game->map[i])
	{
		if(game->map[i][ft_strlen(game->map[i])] != WALL)
			return error_exit(game, "map isn't valid");
		i++;
	}
}
void	are_char_valid(t_map *game)
{
	int i;
	int j;
	char *str;

	i =0;
	str ="10PEC";
	while(game->map[i])
	{
		j =0;
		while(game->map[i][j])
		{
			if(!ft_strchr(str, game->map[i][j]))
				return error_exit(game, "map isn't valid");
			j++;
		}
		i++;
	}
}

void count_info(t_map *game)
{
	int i;
	int j;

	i = 0;

	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j]= COLLECTIBLES)
			game->collectibles++;
			if(game->map[i][j] = MAP_EXIT )
			game->exit++;
			if(game->map[i][j] = PLAYER)
			game->spawn++;		
		}			
		i++;
	}
	check_info( game,  game->collectibles, game->spawn, game->exit); 
}
void check_info(t_map *game, int collectibles, int spawn, int exit)
{
	if (collectibles < 1)
		return error_exit(game, "map doesn't have enough collectibles");
	if (spawn != 1)
		return error_exit(game, " map has more or less than 1 spawn");
	if (exit != 1)
		return error_exit(game, " map has more or less than 1 exit") ;
}
