/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:58:31 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:58:34 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	player_dir_2(t_cub *cub)
{
	if (cub->plr.dir_symbol == 'W')
	{
		cub->plr.dirY = 0;
		cub->plr.dirX = -1;
		cub->plr.planeY = -0.66;
		cub->plr.planeX = 0;
	}
	else if (cub->plr.dir_symbol == 'E')
	{
		cub->plr.dirY = 0;
		cub->plr.dirX = 1;
		cub->plr.planeY = 0.66;
		cub->plr.planeX = 0;
	}
}

void			player_dir(t_cub *cub)
{
	if (cub->plr.dir_symbol == 'N')
	{
		cub->plr.dirY = -1;
		cub->plr.dirX = 0;
		cub->plr.planeY = 0;
		cub->plr.planeX = 0.66;
	}
	else if (cub->plr.dir_symbol == 'S')
	{
		cub->plr.dirY = 1;
		cub->plr.dirX = 0;
		cub->plr.planeY = 0;
		cub->plr.planeX = -0.66;
	}
	else
		player_dir_2(cub);
}
