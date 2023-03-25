/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:53:37 by ihovhann          #+#    #+#             */
/*   Updated: 2021/06/17 11:53:54 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

static void			index_3
	(char *line, int id, int index, t_cub *cub)
{
	char *tmp;

	tmp = &line[index];
	if (id == 6)
		cub->p.spr_tex = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 7)
	{
		space_in_rgb(tmp, cub);
		get_floor(tmp, cub);
		check_floor(cub);
	}
	else if (id == 8)
	{
		space_in_rgb(tmp, cub);
		get_ceilling(tmp, cub);
		check_ceiling(cub);
	}
}

static void			index_2(char *line, int id, int index, t_cub *cub)
{
	char *tmp;

	while (line[index] == ' ' || line[index] == '\t')
		++index;
	tmp = &line[index];
	if (id == 1)
	{
		cub->p.res_w = ft_atoi(tmp);
		tmp += ft_num_digit(cub->p.res_w);
		cub->p.res_l = ft_atoi(tmp);
		resolution(cub);
	}
	else if (id == 2)
		cub->p.n_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 3)
		cub->p.s_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 4)
		cub->p.w_texture = ft_substr(line, index, ft_strlen(tmp));
	else if (id == 5)
		cub->p.e_texture = ft_substr(line, index, ft_strlen(tmp));
	else
		index_3(line, id, index, cub);
}

static	void		index_1(char *line, t_cub *cub)
{
	int index;

	index = 0;
	while (line[index] == ' ' || line[index] == '\t')
		++index;
	if (line[index] == 'R')
		index_2(line, 1, ++index, cub);
	else if (line[index] == 'F')
		index_2(line, 7, ++index, cub);
	else if (line[index] == 'C')
		index_2(line, 8, ++index, cub);
	else if (line[index++] == 'N' && line[index] == 'O')
		index_2(line, 2, ++index, cub);
	else if (line[--index] == 'S' && line[++index] == 'O')
		index_2(line, 3, ++index, cub);
	else if (line[index] == 'W' && line[++index] == 'E')
		index_2(line, 4, ++index, cub);
	else if (line[index] == 'E' && line[++index] == 'A')
		index_2(line, 5, ++index, cub);
	else if (line[--index] == 'S' && !ft_isalpha(line[++index]))
		index_2(line, 6, index, cub);
}

void				parsing(char **argv, t_cub *cub)
{
	int		fd;
	int		coll_line;
	char	*line;

	coll_line = 0;
	if ((fd = open(argv[1], O_RDONLY)) && fd == -1)
		error("Error\nFile not found or not open", cub);
	while (ft_get_next_line(fd, &line) && coll_line++ != 8)
	{
		if (ft_strlen(line) == 0)
			coll_line--;
		else
		{
			space_tab(line, cub);
			index_1(line, cub);
			if (coll_line == 8)
			{
				check_all(cub);
				break ;
			}
		}
		free(line);
	}
	free(line);
	map_parsing(fd, cub);
}
