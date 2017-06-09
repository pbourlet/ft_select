/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 15:54:07 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	ft_test_size(t_slt *t)
{
	struct winsize	w;
	int				n;

	ioctl(0, TIOCGWINSZ, &w);
	n = (w.ws_col * w.ws_row) / ((t->wlen + 2) * t->sac);
	if (!n || w.ws_col < t->wlen + 1)
	{
		ft_putstr_fd("too small\r", 0);
		return (1);
	}
	return (0);
}

static int	ft_modif(t_slt *t, char **av)
{
	int b;

	b = ft_test_size(t);
	if (!b && ((t->i == t->cur && t->bf[0] == 32) || t->slt[t->i] == 1))
		ft_selection(t, av);
	if ((t->bf[0] == 27 && (t->bf[2] == 68 || t->bf[2] == 67)))
		t->cur = ft_move(t, av);
	return (b);
}

static void	ft_off(void)
{
	ft_putstr_fd(tgetstr("me", NULL), 0);
	ft_putstr_fd("\e[0m", 0);
}

void		ft_print(t_slt *t, char **av, int len)
{
	t->i = 1;
	t->size = ft_winsize();
	t->l = 0;
	while (!t->b && t->i <= t->sac)
	{
		t->b = ft_modif(t, av);
		!t->b ? ft_color() : 0;
		if (av[t->i] && !t->b)
		{
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
	t->b = 0;
	ft_return(t);
}
