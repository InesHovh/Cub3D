/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:58:49 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:58:51 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y + cub->plr.dirY * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y += cub->plr.dirY * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x + cub->plr.dirX * s)] == '*')
		cub->plr.x += cub->plr.dirX * s;
}

void	move_back(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y - cub->plr.dirY * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y -= cub->plr.dirY * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x - cub->plr.dirX * s)] == '*')
		cub->plr.x -= cub->plr.dirX * s;
}

void	move_left(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y - cub->plr.dirX * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y -= cub->plr.dirX * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x + cub->plr.dirY * s)] == '*')
		cub->plr.x += cub->plr.dirY * s;
}

void	move_right(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y + cub->plr.dirX * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y += cub->plr.dirX * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x - cub->plr.dirY * s)] == '*')
		cub->plr.x -= cub->plr.dirY * s;
}

void	turn_right(t_cub *cub, double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->plr.dirY;
	old_plane_x = cub->plr.planeY;
	cub->plr.dirY = cub->plr.dirY * cos(-r) - cub->plr.dirX * sin(-r);
	cub->plr.dirX = old_dir_x * sin(-r) + cub->plr.dirX * cos(-r);
	cub->plr.planeY = cub->plr.planeY * cos(-r) - cub->plr.planeX * sin(-r);
	cub->plr.planeX = old_plane_x * sin(-r) + cub->plr.planeX * cos(-r);
}
