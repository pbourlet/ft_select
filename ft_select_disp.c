/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:25:49 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 20:13:41 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

static void	ft_to_zero(t_slt *t, int ac)
{
	ft_memset(t->bf, 0, 4);
	ft_memset(t->slt, 0, 2048);
	t->i = 1;
	t->cur = 1;
	t->sac = ac - 1;
	g_signo = 0;
	tputs(tgetstr("vi", NULL), 1, &ft_putin);
}

void		ft_return(t_slt *t)
{
	while (t->l)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putin);
		t->l--;
	}
	tputs(tgetstr("cr", NULL), 0, &ft_putin);
	t->size = ft_winsize();
}

void		ft_select_disp(int ac, char **av, int len)
{
	t_slt	t;

	ft_to_zero(&t, ac);
	while (!((t.bf[0] == 27 && t.bf[2] == 0) || t.bf[0] == 10) && t.cur != -1)
	{
		if (t.bf[0] == 127 || (t.bf[0] == 27 && t.bf[1] == 91 &&
		t.bf[2] == 51 && t.bf[3] == 126))
			av[t.cur] = ft_del(&t);
		ft_print(&t, av, len);
		if (!g_signo)
			t.cur != -1 ? read(0, t.bf, 4) : 0;
		g_signo = 0;
	}
	t.bf[0] != 27 ? ft_print_selection(av, t, len) : 0;
}
