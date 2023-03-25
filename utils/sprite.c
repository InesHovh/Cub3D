/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:59:07 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:59:08 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_2(t_cub *cub)
{
	int width;
	int height;

	if (!(cub->t_spr.img = mlx_xpm_file_to_image(cub->mlx,
									cub->p.spr_tex, &width, &height)))
		error("Error\nNo texture found for the sprite", cub);
	cub->t_spr.addr = mlx_get_data_addr(cub->t_spr.img,
	&cub->t_spr.bits_per_pixel, &cub->t_spr.line_length, &cub->t_spr.endian);
}

void	get_sprite(t_cub *cub)
{
	int width;
	int height;

	if (!(cub->t_n.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.n_texture, &width, &height)))
		error("Error\nNo texture found for North", cub);
	cub->t_n.addr = mlx_get_data_addr(cub->t_n.img, &cub->t_n.bits_per_pixel,
									&cub->t_n.line_length, &cub->t_n.endian);
	if (!(cub->t_s.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.s_texture, &width, &height)))
		error("Error\nNo texture found for the South", cub);
	cub->t_s.addr = mlx_get_data_addr(cub->t_s.img, &cub->t_s.bits_per_pixel,
					&cub->t_s.line_length, &cub->t_s.endian);
	if (!(cub->t_w.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.w_texture, &width, &height)))
		error("Error\nNo texture found for the West", cub);
	cub->t_w.addr = mlx_get_data_addr(cub->t_w.img, &cub->t_w.bits_per_pixel,
									&cub->t_w.line_length, &cub->t_w.endian);
	if (!(cub->t_e.img = mlx_xpm_file_to_image(cub->mlx,
						cub->p.e_texture, &width, &height)))
		error("Error\nNo texture found for the East", cub);
	cub->t_e.addr = mlx_get_data_addr(cub->t_e.img, &cub->t_e.bits_per_pixel,
									&cub->t_e.line_length, &cub->t_e.endian);
	get_sprite_2(cub);
}
