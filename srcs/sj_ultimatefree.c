/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_ultimatefree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:42:46 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:42:47 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ult_i_to_vii(int ret, t_cub *cub)
{
	if (C->path_no)
		free(C->path_no);
	if (C->path_so)
		free(C->path_so);
	if (C->path_we)
		free(C->path_we);
	if (C->path_ea)
		free(C->path_ea);
	if (C->path_sprit)
		free(C->path_sprit);
	if (C->kr)
		free(C->kr);
	ult_vii_to_xii(ret, cub);
}

void	ult_vii_to_xii(int ret, t_cub *cub)
{
	int		i;

	i = 0;
	if (C->line_map)
		free(C->line_map);
	if (C->tab_map)
	{			
		while (C->tab_map[i])
			i++;
		while (i)
			free(C->tab_map[i--]);
		free(C->tab_map[i]);
		free(C->tab_map);
	}
	ult_xii_to_xvii(ret, cub);
}

void	ult_xii_to_xvii(int ret, t_cub *cub)
{
	if (C->K)
		free(C->K);
	if (C->SP)
		free(C->SP);
	if (C->CS)
		free(C->CS);
	if (C->bmp)
		free(C->bmp);
	if (C)
		free(C);
	ret = 0;
}
