/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:09:03 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/22 13:34:27 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (game->map[i] && game->map[i] != NULL && game->map[i][j] != '\0')
	{
		if (game->map[i][j] == 'P')
		{
			game->y = i;
			game->x = j;
			return ;
		}
		if (game->map[i][j] == '\n')
		{
			i++;
			j = 1;
		}
		j++;
	}
}

void	ft_copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	game->cp = game->c;
	map_copy = malloc(sizeof(char *) * (game->nlines + 1));
	if (!map_copy)
		return ;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	ft_player_position(game);
	ft_check_path(game, game->x, game->y, map_copy);
	free_map(map_copy);
	if (game->cp != 0 || game->f != 1)
		exit_game(game, 0);
}

void	ft_check_path(t_game *game, int x, int y, char **map_copy)
{
	if (map_copy[y][x] == 'G' || map_copy[y][x] == '1')
		return ;
	else if (map_copy[y][x] == 'C')
		game->cp--;
	else if (map_copy[y][x] == 'E')
	{
		game->f = 1;
		return ;
	}
	map_copy[y][x] = 'G';
	ft_check_path(game, x + 1, y, map_copy);
	ft_check_path(game, x - 1, y, map_copy);
	ft_check_path(game, x, y + 1, map_copy);
	ft_check_path(game, x, y - 1, map_copy);
}
