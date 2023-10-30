/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:10:50 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/22 13:32:33 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_first_and_last_line(t_game map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map.map[0][j] == '1')
		j++;
	while (map.map[map.nlines - 2] && map.map[map.nlines - 2][i] == '1')
		i++;
	if (j == (ft_strlen(map.map[0]) - 2) \
	&& (i == ft_strlen(map.map[map.nlines - 2])))
		return (1);
	return (0);
}

static int	ft_check_content(t_game *map)
{
	static int	i;
	int			j;

	j = -1;
	while (map->map[i] && map->map[i] != NULL && map->map[i][++j] != '\0')
	{
		if (map->map[i][j] != '1' &&
		map->map[i][j] != '0' && map->map[i][j] != 'P' \
		&& map->map[i][j] != 'C' && map->map[i][j] != 'E' \
		&& map->map[i][j] != '\n')
			return (0);
		if (map->map[i][j] == 'P')
			map->p++;
		if (map->map[i][j] == 'C')
			map->c++;
		if (map->map[i][j] == 'E')
			map->e++;
		if (map->map[i][j] == '\n' && ++i)
			j = 1;
	}
	if (map->p == 1 && map->e == 1 && map->c >= 1)
		return (1);
	return (0);
}

static int	ft_check_position(t_game map)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	l = map.nlines - 1;
	while (map.map[i] && map.map[i][0] == '1')
		i++;
	while (map.map[j] && (map.map[j][ft_strlen(map.map[j]) - 3] == '1'))
		j++;
	if (i == l && j == l)
		return (1);
	return (0);
}

static int	ft_is_line_equal(t_game map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map.map[0]);
	while (ft_strlen(map.map[i]) == j)
		i++;
	if (map.map[i] == NULL \
	|| ft_strlen(map.map[0]) == ft_strlen(map.map[i]) + 2)
		return (1);
	return (0);
}

int	ft_game_validations(t_game *map)
{
	if (ft_is_line_equal(*map) && ft_first_and_last_line(*map)
		&& ft_check_position(*map) && ft_check_content(map))
		return (1);
	exit_game(map, 0);
	return (0);
}
