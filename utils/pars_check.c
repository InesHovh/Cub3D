/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:53:19 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:53:20 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_all(t_cub *cub)
{
	if (cub->p.res_l == 0 || cub->p.res_w == 0
	|| ft_strlen(cub->p.n_texture) == 0
	|| ft_strlen(cub->p.s_texture) == 0
	|| ft_strlen(cub->p.w_texture) == 0
	|| ft_strlen(cub->p.e_texture) == 0 || ft_strlen(cub->p.spr_tex) == 0
	|| cub->p.f_flag != 1 || cub->p.c_flag != 1)
	{
		ft_putstr_fd("Error\nWas set not all edificatory or ", 1);
		error("are there repetitions", cub);
	}
}

void	space_in_rgb(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			error("Error\nA space was found in color", cub);
		++i;
	}
}

void	check_ceiling(t_cub *cub)
{
	if ((cub->p.c_r > 255 || cub->p.c_r < 0) ||
	(cub->p.c_g > 255 || cub->p.c_g < 0) ||
	(cub->p.c_b > 255 || cub->p.c_b < 0))
		error("Error\nNot a valid ceilling color", cub);
	cub->p.c_flag = 1;
}

void	check_floor(t_cub *cub)
{
	if ((cub->p.f_r > 255 || cub->p.f_r < 0) ||
	(cub->p.f_g > 255 || cub->p.f_g < 0) ||
	(cub->p.f_b > 255 || cub->p.f_b < 0))
		error("Error\nNot a valid floor color", cub);
	cub->p.f_flag = 1;
}

void	resolution(t_cub *cub)
{
	int width;
	int height;

	mlx_get_screen_size(&cub->mlx, &width, &height);
	if (cub->p.res_w < 0 || cub->p.res_l < 0)
		error("Error\nNot a valid resolution", cub);
	if (cub->p.res_w > width || cub->p.res_l > height)
	{
		cub->p.res_w = width;
		cub->p.res_l = height;
	}
}
