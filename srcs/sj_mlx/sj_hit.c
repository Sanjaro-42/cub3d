/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:50:37 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:05:43 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_hit(t_cub *cub)
{
	if (C->CS->side == 0)
	{
		if (C->CS->mapx < C->CS->pos_x)
			C->CS->side = 1;
	}
	else
	{
		if (C->CS->mapy < C->CS->pos_y)
			C->CS->side = 3;
	}
}
