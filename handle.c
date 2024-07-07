/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmedjahe <mmedjahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:02:50 by mmedjahe          #+#    #+#             */
/*   Updated: 2024/07/05 00:23:43 by mmedjahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void map_free(t_map *game)
{
	ft_free_split(game->map);
	game->map == NULL;
}


void	is_ber(t_map *game, char *str)
{
	int	i;
	int n;
	char *ber;

	ber = ".ber";
	n =0;

	i = ft_strlen(str - 4);

	while(str[i])
	{
		if(str[i] != ber[n])
			error_exit(game, "file is not a .ber");
		i++;
		n++;
	}
}

void error_exit(t_map *game, const char *str)
{
	ft_printf(RED "%s\n", str);
	map_free(game);
	free_mlx_img(&game->img);
	close_game(game);
	exit(0);
}
void is_map_empty(t_map *game)
{
	int i;
	
	i =0;
	if(game-> map[i] == NULL)
		return error_exit(game, "Map doesn't exit");
}
void valid_msg(const char *str)
{
	ft_printf(GREEN "%s\n", str);
}