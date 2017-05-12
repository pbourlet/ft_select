/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:25:49 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/12 15:07:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

static void	ft_to_zero(t_slt *t, int ac, int len, char **av)
{
	ft_memset(t->bf, 0, 4);
	ft_memset(t->slt, 0, 2048);
	t->i = 1;
	t->cur = 1;
	t->sac = ac - 1;
	t->wlen = len;
	t->sav = av;
	tputs(tgetstr("vi", NULL), 1, &ft_putin);
}

void		ft_select_disp(int ac, char **av, int len)
{
	ft_to_zero(&g_t, ac, len, av);
	while (!((g_t.bf[0] == 27 && g_t.bf[2] == 0) || g_t.bf[0] == 10)
	&& g_t.cur != -1)
	{
		if (g_t.bf[0] == 127 || (g_t.bf[0] == 27 && g_t.bf[1] == 91 &&
		g_t.bf[2] == 51 && g_t.bf[3] == 126))
			av[g_t.cur] = ft_del(&g_t);
		ft_print(&g_t, av, len);
		g_t.cur != -1 ? read(0, g_t.bf, 4) : 0;
		tputs(tgetstr("cd", NULL), 0, ft_putin);
	}
	g_t.bf[0] != 27 ? ft_print_selection(av, g_t, len) :
						tputs(tgetstr("te", NULL), 0, &ft_putin);
}
