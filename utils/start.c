/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:59:24 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:59:25 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void		malloc_arrays(t_cub *cub)
{
	if (!(cub->x = malloc(sizeof(float) * cub->p.col_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->y = malloc(sizeof(float) * cub->p.col_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->dist = malloc(sizeof(float) * cub->p.col_sprite)))
		error("Error\nNo memory allocated", cub);
	if (!(cub->close_sprite = malloc(sizeof(double) * cub->p.res_w)))
		error("Error\nNo memory allocated", cub);
}

static	void		print_sprite(t_cub *cub)
{
	t_norm_print_sprite	s;
	int					i;
	int					y;
	int					stripe;

	i = -1;
	while (++i < cub->p.col_sprite)
	{
		set_sprite(cub, &s, &i);
		stripe = s.draw_start_x;
		while (stripe < s.draw_end_x)
		{
			s.tex_x = (int)(256 * (stripe - (-s.sprite_width / 2
			+ s.sprite_screen_x)) * TEXWIDTH / s.sprite_width) / 256;
			if (s.transform_y > 0 && stripe > 0 && stripe < cub->p.res_w
						&& s.transform_y < cub->close_sprite[stripe])
			{
				sprite_norm(cub, &s, &y, &stripe);
			}
			++stripe;
		}
	}
}

static	void		print_map(t_cub *cub)
{
	t_norm_print_map	n;
	int					x;
	int					y;

	cub->data.img = mlx_new_image(cub->mlx, cub->p.res_w, cub->p.res_l);
	cub->data.addr = mlx_get_data_addr(cub->data.img,
	&cub->data.bits_per_pixel, &cub->data.line_length, &cub->data.endian);
	x = -1;
	while (++x < cub->p.res_w)
	{
		coordinat_direction(&n, &x, cub);
		ray_direction(&n, cub);
		while (n.hit == 0)
			ray_wall_stop(&n, cub);
		distance(&n, cub, &x);
		n.step = 1.0 * TEXHEIGTH / n.line_height;
		n.tex_pos = (n.draw_start - cub->p.res_l
				/ 2 + n.line_height / 2) * n.step;
		y = -1;
		while (++y < cub->p.res_l)
			fill_colors(&n, cub, &x, &y);
	}
	sort(cub);
	print_sprite(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->data.img, 0, 0);
}

static int			key_hook(int keycode, t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	if (keycode == 13)
		move_forward(cub, 0.3);
	if (keycode == 1)
		move_back(cub, 0.3);
	if (keycode == 0)
		move_left(cub, 0.3);
	if (keycode == 2)
		move_right(cub, 0.3);
	if (keycode == 124)
		turn_right(cub, 0.2);
	if (keycode == 123)
		turn_left(cub, 0.2);
	if (keycode == 53)
		close_win(cub);
	print_map(cub);
	return (0);
}

void				start(t_cub *cub, int argc)
{
	cub->plr.y = (double)cub->p.player_y + 0.5;
	cub->plr.x = (double)cub->p.player_x + 0.5;
	cub->p.col_sprite = count(cub);
	malloc_arrays(cub);
	where_is_sprite(cub);
	player_dir(cub);
	cub->mlx = mlx_init();
	cub->mlx_wind = mlx_new_window(cub->mlx, cub->p.res_w,
									cub->p.res_l, "cub3D");
	get_sprite(cub);
	print_map(cub);
	if (argc == 3)
		screen(cub);
	else
	{
		mlx_hook(cub->mlx_wind, 2, 1L << 0, key_hook, cub);
		mlx_hook(cub->mlx_wind, 17, 1L << 0, close_win, cub);
		mlx_loop(cub->mlx);
	}
}
