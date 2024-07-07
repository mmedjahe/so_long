/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:12:03 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/05 00:39:41 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map(t_map *game, char *file)
{
	int fd;
	char *line;
	char *temp;

	fd = check_file(game, file);
	temp = get_next_line(fd);
	line = ft_strdup("");
	while(temp != NULL)
	{
		line = ft_strjoin(line, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(file);
	game->map = ft_split(line, '\n'); 
	game->height = check_map_height(game->map);
}
int	check_map_height(char **map)
{
	int i;

	i =0;
	while(map[i])
		i++;
	return(i);
}
int check_file(t_map *game, int fd)
{
	int file;
	
	file = open(fd, __O_DIRECTORY);
	if(file != 1)
	{
		close(file);
		error_exit(game, "error map");
	}
	file = open(fd, O_RDONLY);
	if(file != 1)
	{
		close(file);
		error_exit(game, "error map");
	}
	return(file);
}

void verif_all(t_map *game, char *arg)
{
	ft_bzero(game, sizeof(t_map));
	is_ber(game, arg);
	init_map(game, arg);
	are_char_valid(game);
	count_info(game);
	is_rectangle(game);
	full_wall(game);
	loc_player(game);
	ft_flood(game);
}