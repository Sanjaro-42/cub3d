/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_check_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 01:11:25 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 02:44:35 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_check_tab(t_cub *cub)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (cub->tab_map[i])
		i++;
	while (cub->tab_map[i - 1][y])
		if (cub->tab_map[i - 1][y++] != '1')
			return (-12);
	if ((ft_strlen(cub->tab_map[0]) * i) != ft_strlen(cub->line_map))
		return (-12);
	if (!ft_strchr(cub->line_map, 'S') && !ft_strchr(cub->line_map, 'W')
		&& !ft_strchr(cub->line_map, 'E') && !ft_strchr(cub->line_map, 'N'))
		return (-12);
	return (sj_ckeck_double_local(cub));
}

int		sj_ckeck_double_local(t_cub *cub)
{
	if (ft_strchr(cub->line_map, 'S'))
	{
		if (ft_strchr(cub->line_map, 'E') || ft_strchr(cub->line_map, 'W')
			|| ft_strchr(cub->line_map, 'N')
			|| ft_strchr(ft_strchr(cub->line_map, 'S') + 1, 'S'))
			return (-12);
		cub->pos = ft_strchr(cub->line_map, 'S')[0];
	}
	if (ft_strchr(cub->line_map, 'E'))
	{
		if (ft_strchr(cub->line_map, 'S') || ft_strchr(cub->line_map, 'W')
			|| ft_strchr(cub->line_map, 'N')
			|| ft_strchr(ft_strchr(cub->line_map, 'E') + 1, 'E'))
			return (-12);
		cub->pos = ft_strchr(cub->line_map, 'E')[0];
	}
	return (sj_ckeck_double_local_tho(cub));
}

int		sj_ckeck_double_local_tho(t_cub *cub)
{
	if (ft_strchr(cub->line_map, 'W'))
	{
		if (ft_strchr(cub->line_map, 'E') || ft_strchr(cub->line_map, 'S')
			|| ft_strchr(cub->line_map, 'N')
			|| ft_strchr(ft_strchr(cub->line_map, 'W') + 1, 'W'))
			return (-12);
		cub->pos = ft_strchr(cub->line_map, 'W')[0];
	}
	if (ft_strchr(cub->line_map, 'N'))
	{
		if (ft_strchr(cub->line_map, 'E') || ft_strchr(cub->line_map, 'W')
			|| ft_strchr(cub->line_map, 'S')
			|| ft_strchr(ft_strchr(cub->line_map, 'N') + 1, 'N'))
			return (-12);
		cub->pos = ft_strchr(cub->line_map, 'N')[0];
	}
	return (0);
}

int		sj_space_skip(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}