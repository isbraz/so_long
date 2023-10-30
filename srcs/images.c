/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:21:53 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/26 11:14:16 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_images(t_window *window)
{
	int	i;

	window->bg = mlx_xpm_file_to_image(window->mlx, "../i/bg.xpm", &i, &i);
	window->cimg = mlx_xpm_file_to_image(window->mlx, "../i/c.xpm", &i, &i);
	window->eimg = mlx_xpm_file_to_image(window->mlx, "../i/e.xpm", &i, &i);
	window->pf = mlx_xpm_file_to_image(window->mlx, "../i/n1.xpm", &i, &i);
	window->pl = mlx_xpm_file_to_image(window->mlx, "../i/n4.xpm", &i, &i);
	window->pr = mlx_xpm_file_to_image(window->mlx, "../i/n7.xpm", &i, &i);
	window->pu = mlx_xpm_file_to_image(window->mlx, "../i/n10.xpm", &i, &i);
	window->wimg = mlx_xpm_file_to_image(window->mlx, "../i/w.xpm", &i, &i);
	window->pcurrent = window->pf;
}

void	put_image(t_window *window, int y, int x, int option)
{
	if (option == 0)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, \
		window->wimg, x * 32, y * 32);
	}
	if (option == 1)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->bg, \
		x * 32, y * 32);
	}
	if (option == 2)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->cimg, \
		x * 32, y * 32);
	}
	if (option == 3)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->pcurrent, \
		x * 32, y * 32);
	}
	if (option == 4)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->eimg, \
		x * 32, y * 32);
	}
}

void	print_map(t_game *game, t_window *window)
{
	int			i;
	int			j;
	char		*moves;

	i = -1;
	moves = ft_itoa(game->m);
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				put_image(window, i, j, 0);
			if (game->map[i][j] == '0')
				put_image(window, i, j, 1);
			if (game->map[i][j] == 'C')
				put_image(window, i, j, 2);
			if (game->map[i][j] == 'E')
				put_image(window, i, j, 4);
			if (game->map[i][j] == 'P')
				put_image(window, i, j, 3);
		}
	}
	mlx_string_put(window->mlx, window->mlx_win, 10, 20, 0xffffffff, moves);
	free(moves);
}
