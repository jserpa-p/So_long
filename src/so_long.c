/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:59 by jserpa-p          #+#    #+#             */
/*   Updated: 2022/02/14 16:15:54 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_filling(t_markers *mark)
{
	int	w;
	int	l;

	w = 0;
	while (mark->map[w])
	{
		l = 0;
		while (mark->map[w][l])
		{
			put_image(mark->map[w][l], mark, w, l);
			l++;
		}
		w++;
	}
}

void	init_game(t_markers *mark)
{
	mark->mlx = mlx_init();
	mark->win = mlx_new_window(mark->mlx, mark->map_len * 64, \
								mark->map_wid * 64, "So Long!");
	map_filling(mark);
	mlx_hook(mark->win, 2, 0, lets_push, mark);
	mlx_hook(mark->win, 17, 1L << 2, ft_close_x, mark);
	mlx_loop_hook(mark->mlx, patrol_animation, mark);
	mlx_loop(mark->mlx);
}

void	so_long(char *map)
{
	t_markers	mark;

	init_markers(&mark);
	map_width_counter(map, &mark);
	map_parser(map, &mark);
	map_checker(&mark);
	init_game(&mark);
}
