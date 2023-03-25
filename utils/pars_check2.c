/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:53:28 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:53:30 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			get_floor(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.f_r = ft_atoi(tmp);
	else
		error("Error\nNot set f_r", cub);
	tmp += ft_num_digit(cub->p.f_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.f_g = ft_atoi(tmp);
	else
		error("Error\nNot set f_g", cub);
	tmp += ft_num_digit(cub->p.f_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.f_b = ft_atoi(tmp);
	else
		error("Error\nNot set f_b", cub);
}

void			get_ceilling(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.c_r = ft_atoi(tmp);
	else
		error("Error\nNot set c_r", cub);
	tmp += ft_num_digit(cub->p.c_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.c_g = ft_atoi(tmp);
	else
		error("Error\nNot set c_g", cub);
	tmp += ft_num_digit(cub->p.c_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.c_b = ft_atoi(tmp);
	else
		error("Error\nNot set c_b", cub);
}

void			space_in_map(char *str, t_cub *cub)
{
	int i;

	i = 0;
	{
		if (str[i] != ' ')
			return ;
		++i;
	}
	ft_putstr_fd("Error\nThere is an empty line ", 1);
	error("with spaces at the end of the map", cub);
}

static	void	check_symbols_2(int *flag, int *i, int *j, t_cub *cub)
{
	if (cub->p.map[*i][*j] == 'N' || cub->p.map[*i][*j] == 'S'
	|| cub->p.map[*i][*j] == 'E' || cub->p.map[*i][*j] == 'W')
	{
		if (*flag == 0)
		{
			*flag = 1;
			cub->p.player = &cub->p.map[*i][*j];
			cub->p.player_y = *i;
			cub->p.player_x = *j;
		}
		else
			error("Error\nThe player meets more than 1 time", cub);
	}
}

void			check_symbols(int size, t_cub *cub)
{
	int i;
	int j;
	int flag;

	i = -1;
	flag = 0;
	while (++i != size)
	{
		j = 0;
		while (cub->p.map[i][j] != '\0')
		{
			check_symbols_2(&flag, &i, &j, cub);
			if (cub->p.map[i][j] == ' ' || cub->p.map[i][j] == '0'
			|| cub->p.map[i][j] == '1' || cub->p.map[i][j] == '2'
			|| cub->p.map[i][j] == 'N' || cub->p.map[i][j] == 'S'
			|| cub->p.map[i][j] == 'E' || cub->p.map[i][j] == 'W')
				++j;
			else
				error("Error\nWrong symbol in the map", cub);
		}
	}
	if (flag == 0)
		error("Error\nThe player never meets", cub);
}
