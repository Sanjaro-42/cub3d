/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strilen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:37:13 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:02:32 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int			ft_strilen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
