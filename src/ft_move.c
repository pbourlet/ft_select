/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:49:48 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 15:53:58 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

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

int				ft_move(t_slt *t, char **av)
{
	int add;

	add = (t->bf[2] == 68 ? -1 : 1);
	if (ft_test(t->sac, av))
	{
		if (add == 1 ? (t->cur + add > t->sac) : (t->cur + add <= 0))
		{
			t->cur = add == 1 ? 1 : t->sac;
			while (!av[t->cur])
				t->cur = t->cur + add;
		}
		else
		{
			t->cur = t->cur + add;
			while (!av[t->cur])
			{
				if (add == 1 ? (t->cur + add > t->sac) : (t->cur + add <= 0))
					t->cur = add == 1 ? 1 : t->sac;
				else
					t->cur = t->cur + add;
			}
		}
	}
	ft_memset(t->bf, 0, 4);
	return (ft_test(t->sac, av) ? t->cur : -1);
}
