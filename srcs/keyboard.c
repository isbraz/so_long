/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:47:56 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/25 15:34:47 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_player(t_game *game, int y, int x)
{
	if (game->map[game->y + y][game->x + x] != '1' \
	&& game->map[game->y + y][game->x + x] != 'E')
	{
		if (game->map[game->y + y][game->x + x] == 'C')
			game->c--;
		game->map[game->y][game->x] = '0';
		game->y += y;
		game->x += x;
		game->map[game->y][game->x] = 'P';
		game->m++;
	}
	if (game->map[game->y + y][game->x + x] == 'E' && game->c == 0)
		exit_game(game, 2);
	print_map(game, &game->win);
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		exit_game(game, 1);
	if (keycode == KEY_W)
	{
		game->win.pcurrent = game->win.pu;
		ft_move_player(game, -1, 0);
	}
	if (keycode == KEY_S)
	{
		game->win.pcurrent = game->win.pf;
		ft_move_player(game, 1, 0);
	}
	if (keycode == KEY_A)
	{
		game->win.pcurrent = game->win.pl;
		ft_move_player(game, 0, -1);
	}
	if (keycode == KEY_D)
	{
		game->win.pcurrent = game->win.pr;
		ft_move_player(game, 0, 1);
	}
	return (0);
}
