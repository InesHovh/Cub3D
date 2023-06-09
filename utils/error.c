/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:52:11 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:52:13 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(char *str, t_cub *cub)
{
	(void)cub;
	ft_putendl_fd(str, 1);
	exit(1);
}
