/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:59:58 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 12:00:11 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_cub cub;

	arguments(argc, argv, &cub);
	parsing(argv, &cub);
	start(&cub, argc);
	return (0);
}
