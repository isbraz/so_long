/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:49:36 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/09/26 11:17:58 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 4 && ft_strcmp(str + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

int	main(int ac, char **argv)
{
	t_game	game;

	if (ac != 2 || (!check_extension(argv[1])))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	ft_alocate_map(&game, argv[1]);
	ft_game_validations(&game);
	ft_copy_map(&game);
	game.win.mlx = mlx_init();
	game.win.mlx_win = mlx_new_window(game.win.mlx, \
	(ft_strlen(game.map[0]) - 2) * 32, (game.nlines - 1) * 32, "Naruto");
	ft_init_images(&game.win);
	print_map(&game, &game.win);
	mlx_hook(game.win.mlx_win, 17, 1L << 0, exit_gametwo, &game);
	mlx_hook(game.win.mlx_win, 2, 1L << 0, ft_key, &game);
	mlx_loop(game.win.mlx);
}
