/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:51:40 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:51:42 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_colors(t_norm_print_map *n, t_cub *cub, int *x, int *y)
{
	if (*y < n->draw_start)
		my_mlx_pixel_put(&cub->data, *x, *y,
		my_rgb(cub->p.c_r, cub->p.c_g, cub->p.c_b));
	if (*y >= n->draw_start && *y <= n->draw_end)
		attach_textures(n, cub, x, y);
	if (*y > n->draw_end && *y < cub->p.res_l)
		my_mlx_pixel_put(&cub->data, *x, *y,
		my_rgb(cub->p.f_r, cub->p.f_g, cub->p.f_b));
}

void	distance(t_norm_print_map *n, t_cub *cub, int *x)
{
	if (n->side == 0)
		n->perp_wall_dist = (n->map_x - cub->plr.y
			+ (1 - n->step_x) / 2) / n->ray_dir_x;
	else
		n->perp_wall_dist = (n->map_y - cub->plr.x
			+ (1 - n->step_y) / 2) / n->ray_dir_y;
	cub->close_sprite[*x] = n->perp_wall_dist;
	n->line_height = (int)(cub->p.res_l / n->perp_wall_dist);
	n->draw_start = -n->line_height / 2 + cub->p.res_l / 2;
	if (n->draw_start < 0)
		n->draw_start = 0;
	n->draw_end = n->line_height / 2 + cub->p.res_l / 2;
	if (n->draw_end >= cub->p.res_l)
		n->draw_end = cub->p.res_l - 1;
	if (n->side == 0)
		n->wall_x = cub->plr.x + n->perp_wall_dist * n->ray_dir_y;
	else
		n->wall_x = cub->plr.y + n->perp_wall_dist * n->ray_dir_x;
	n->wall_x -= floor((n->wall_x));
	n->tex_x = (int)(n->wall_x * (double)(TEXWIDTH));
	if (n->side == 0 && n->ray_dir_x > 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
	if (n->side == 1 && n->ray_dir_y < 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
}

void	ray_wall_stop(t_norm_print_map *n, t_cub *cub)
{
	if (n->side_dist_x < n->side_dist_y)
	{
		n->side_dist_x += n->delta_dist_x;
		n->map_x += n->step_x;
		n->side = 0;
	}
	else
	{
		n->side_dist_y += n->delta_dist_y;
		n->map_y += n->step_y;
		n->side = 1;
	}
	if (cub->p.map[n->map_x][n->map_y] == '1')
		n->hit = 1;
}

void	ray_direction(t_norm_print_map *n, t_cub *cub)
{
	if (n->ray_dir_x < 0)
	{
		n->step_x = -1;
		n->side_dist_x = (cub->plr.y - n->map_x) * n->delta_dist_x;
	}
	else
	{
		n->step_x = 1;
		n->side_dist_x = (n->map_x + 1.0 - cub->plr.y) * n->delta_dist_x;
	}
	if (n->ray_dir_y < 0)
	{
		n->step_y = -1;
		n->side_dist_y = (cub->plr.x - n->map_y) * n->delta_dist_y;
	}
	else
	{
		n->step_y = 1;
		n->side_dist_y = (n->map_y + 1.0 - cub->plr.x) * n->delta_dist_y;
	}
}

void	coordinat_direction(t_norm_print_map *n, int *x, t_cub *cub)
{
	n->camera_x = 2 * *x / (double)cub->p.res_w - 1;
	n->ray_dir_x = cub->plr.dirY + cub->plr.planeY * n->camera_x;
	n->ray_dir_y = cub->plr.dirX + cub->plr.planeX * n->camera_x;
	n->map_x = (int)(cub->plr.y);
	n->map_y = (int)(cub->plr.x);
	n->delta_dist_x = sqrt(1 + (n->ray_dir_y * n->ray_dir_y)
							/ (n->ray_dir_x * n->ray_dir_x));
	n->delta_dist_y = sqrt(1 + (n->ray_dir_x * n->ray_dir_x)
							/ (n->ray_dir_y * n->ray_dir_y));
	n->hit = 0;
}
