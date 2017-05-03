/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:49:48 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 19:18:24 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

static int		ft_test(int ac, char **av)
{
	int i;

	i = 1;
	while (i <= ac)
	{
		if (av[i])
			return (1);
		i++;
	}
	return (0);
}

int				ft_move(char *buf, char **av, int ac, int cur)
{
	int add;

	add = (buf[2] == 68 ? -1 : 1);
	if (ft_test(ac, av))
	{
		if (add == 1 ? (cur + add > ac) : (cur + add <= 0))
		{
			cur = add == 1 ? 1 : ac;
			while (!av[cur])
				cur = cur + add;
		}
		else
		{
			cur = cur + add;
			while (!av[cur])
			{
				if (add == 1 ? (cur + add > ac) : (cur + add <= 0))
					cur = add == 1 ? 1 : ac;
				else
					cur = cur + add;
			}
		}
	}
	ft_memset(buf, 0, 4);
	return (ft_test(ac, av) ? cur : -1);
}
