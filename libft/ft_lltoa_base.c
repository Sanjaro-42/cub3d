/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:18:31 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:00:29 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long		ft_len(unsigned long long n, char *base)
{
	long unsigned int	len;

	len = 1;
	while (n /= ft_strlen(base))
		len++;
	return (len);
}

char							*ft_lltoa_base(unsigned long long n, char *base)
{
	char					*str;
	unsigned long long		i;

	i = ft_len(n, base);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = base[n % ft_strllen(base)];
		n /= ft_strllen(base);
	}
	return (str);
}
