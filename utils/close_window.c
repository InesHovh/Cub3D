/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:49:10 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:49:12 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		close_win(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_wind);
	exit(0);
	return (0);
}