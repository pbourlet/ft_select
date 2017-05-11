/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 19:33:19 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	ft_modif(t_slt *t, char **av)
{
	if ((t->i == t->cur && t->bf[0] == 32) || t->slt[t->i] == 1)
		ft_selection(t, av);
	if (t->bf[0] == 27 && (t->bf[2] == 68 || t->bf[2] == 67))
		t->cur = ft_move(t, av);
}

void		ft_print(t_slt *t, char **av, int len)
{
	t->i = 1;
	t->size = ft_winsize();
	t->l = 0;
	while (t->i <= t->sac)
	{
		ft_modif(t, av);
		if (av[t->i])
		{
			t->slt[t->i] == 1 ? tputs(tgetstr("mr", NULL), 0, &ft_putin) : 0;
			t->i == t->cur ? ft_underling() : 0;
			if (len + 1 > t->size)
			{
				ft_putstr_fd("\n\r", 0);
				t->size = ft_winsize();
				t->l += 1;
			}
			ft_putstr_fd(av[t->i], 0);
			ft_off();
			ft_putlenstr_fd(len - ft_strlen(av[t->i]), " ", 0);
			t->size -= (len + 1);
		}
		t->i += 1;
	}
	ft_return(t);
}
