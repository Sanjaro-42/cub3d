/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:07:43 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 03:53:35 by sanjaro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
**	LA LIGNE DANS LINE PUIS SI LA LIGNE CORESPOND A L'ID
**	HOP DANS LA STRUCTURE MAIS SI LA VALEUR DE RETOUR EST
**	INFERIEUR A 0 : VOIR SJ_STDERR SI C'EST == 1 JE PC++
**	PC == NORBRE DE PARSING VALIDER SI != 8 MANQUE DES TRUCS
*/

int		sj_parse_all(t_cub *cub, char **gv)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;
	int		y;

	i = 0;
	y = 0;
	cub->pc = 1;
	ret = 0;
	if ((fd = open(gv[1], 0x0000)) < 0)
		return (1);
	while (get_next_line(fd, &line))
	{
		if ((ret = sj_gnl_parse(line, cub)) < 0)
			return (ret);
	}
	if ((ret = sj_gnl_parse(line, cub)) < 0)
		return (ret);
	if (cub->pc < 10)
		return (-11);
	cub->tab_map = ft_split(cub->line_map, '\n');
	sj_clean_line(cub);
	close(fd);
	// ERROR CHECK
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
	// ERROR CHECK
	return (0);
}

int		sj_gnl_parse(char *line, t_cub *cub)
{
	int		ret;
	int		map;

	ret = 0;
	map = 0;
	if (!line)
		return (-9);
	if ((ret = sj_parse_letter(line, cub) > 0)
		|| (ret = sj_parse_letter_p2(line, cub) > 0))
		cub->pc++;
	if (ret < 0)
		return (ret);
	if (cub->pc > 9)
		map = sj_parsing_map(cub, line);
	if (map < 0)
		return (-12);
	free(line);
	return (0);
}

int		sj_parse_letter(char *line, t_cub *cub)
{
	int		ret;

	if ((ret = sj_parse_r(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_no(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_so(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_we(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	return (0);
}

int		sj_parse_letter_p2(char *line, t_cub *cub)
{
	int ret;

	if ((ret = sj_parse_ea(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_sprit(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_f(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if ((ret = sj_parse_c(line, cub)) < 0)
		return (ret);
	else if (ret == 1)
		return (1);
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}
