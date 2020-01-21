/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:07:43 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 22:34:17 by esidelar    ###    #+. /#+    ###.fr     */
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
	int		retur;

	if ((fd = open(gv[1], 0x0000)) < 0)
		return (1);
	while (get_next_line(fd, &line))
	{
		retur = sj_gnl_parse(line, cub);
		if (retur < 0)
			return (retur);
	}
	retur = sj_gnl_parse(line, cub);
	if (retur < 0)
		return (retur);
	cub->tab_map = ft_split(cub->line_map, '\n');
	sj_clean_line(cub);
	close(fd);
	return (sj_check_tab(cub));
}

int		sj_gnl_parse(char *line, t_cub *cub)
{
	int		ret;
	int		ret2;
	int		map;

	ret = 0;
	ret2 = 0;
	map = 0;
	if (!line)
		return (-9);
	if (!(ret = sj_parse_letter(line, cub)))
		ret2 = sj_parse_letter_p2(line, cub);
	if (ret < 0)
		return (ret);
	if (ret2 < 0)
		return (ret2);
	if (ret || ret2)
		cub->pc++;
	if (cub->pc > 8)
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
	if (ft_strchr(line, '1') && cub->pc < 8)
		return (-11);
	if (!sj_first_line(line) && cub->pc == 8)
		return (-9);
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

int		sj_first_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '1' || str[i] == ' '))
			i++;
		else
			return (0);
	}
	return (1);
}
