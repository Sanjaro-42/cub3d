/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:09:34 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 08:16:19 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int		sj_cub(int ac, char **gv)
{
	t_cub	*cub;
	int		ret;

	ret = 0;
	if (!(C = malloc(sizeof(t_cub) + ret++))
	|| !(C->K = malloc(sizeof(t_key) + ret++ - 1))
	|| !(C->CS = malloc(sizeof(t_recast) + ret++ - 2))
	|| !(C->SP = malloc(sizeof(t_sprite) + ret++ - 3)))
		return (-ret);
	sj_cub_init(cub);
	if (!sj_stderr_argcub(ac, gv, cub))
		exit(EXIT_FAILURE);
	if ((ret = sj_parse_all(cub, gv)) < 0)
	{
		ft_printf(RED);
		ft_printf("Error\n");
		sj_stderr_parsing(ret);
		ult_i_to_vii(ret, cub);
		exit(EXIT_FAILURE);
	}
	sj_init_player(cub);
	sj_creat_new_windows(cub);
	sj_cub_free(cub);
	ult_i_to_vii(-99, cub);
	exit(EXIT_SUCCESS);
}

void	sj_init_player(t_cub *cub)
{
	if (C->res_x > 2560)
		C->res_x = 2560;
	if (C->res_y > 1400)
		C->res_y = 1400;
	C->dbl_pos_x = (int)ft_strchr(C->line_map, C->pos) -
		(int)C->line_map;
	C->dbl_pos_y = C->dbl_pos_x;
	C->dbl_pos_x = (int)C->dbl_pos_x % ft_strlen(C->tab_map[0]) + 0.5;
	C->dbl_pos_y = (int)C->dbl_pos_y / ft_strlen(C->tab_map[0]) + 0.5;
	C->init_pos_x = ft_strchr(C->line_map, C->pos) - C->line_map;
	C->init_pos_y = C->init_pos_x;
	C->init_pos_x = C->init_pos_x % ft_strlen(C->tab_map[0]);
	C->init_pos_y = C->init_pos_y / ft_strlen(C->tab_map[0]);
}

void	sj_cub_free(t_cub *cub)
{
	int		i;

	i = 0;
	while (C->tab_map[i])
		i++;
	while (i)
		free(C->tab_map[--i]);
	free(C->line_map);
	free(C->tab_map);
}
