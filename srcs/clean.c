/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:08:36 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/26 11:25:56 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_window(t_game *game)
{
	mlx_destroy_window(game->win.mlx, game->win.mlx_win);
	mlx_destroy_display(game->win.mlx);
}

static void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->win.mlx, game->win.pu);
	mlx_destroy_image(game->win.mlx, game->win.pf);
	mlx_destroy_image(game->win.mlx, game->win.pl);
	mlx_destroy_image(game->win.mlx, game->win.pr);
	mlx_destroy_image(game->win.mlx, game->win.eimg);
	mlx_destroy_image(game->win.mlx, game->win.cimg);
	mlx_destroy_image(game->win.mlx, game->win.bg);
	mlx_destroy_image(game->win.mlx, game->win.wimg);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_gametwo(t_game *game)
{
	ft_putendl_fd("Lol you're giving up!!!!", 2);
	free_map(game->map);
	destroy_images(game);
	destroy_window(game);
	free(game->win.mlx);
	exit(EXIT_FAILURE);
	return (0);
}

void	exit_game(t_game *game, int f)
{
	if (f == 0)
	{
		ft_putendl_fd("Error", 2);
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
	if (f == 1)
	{
		ft_putendl_fd("Lol you're giving up!!!!", 2);
		free_map(game->map);
		destroy_images(game);
		destroy_window(game);
		free(game->win.mlx);
		exit(EXIT_FAILURE);
	}
	if (f == 2)
	{
		ft_putendl_fd("You won!!!!", 2);
		free_map(game->map);
		destroy_images(game);
		destroy_window(game);
		free(game->win.mlx);
		exit(EXIT_SUCCESS);
	}
}
