/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/12 14:53:35 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print_selection(char **av, t_slt t, int len)
{
	int i;
	int b;

	i = 0;
	b = 0;
	t.size = ft_winsize();
	tputs(tgetstr("te", NULL), 0, &ft_putin);
	while (av[++i])
	{
		if (t.slt[i])
		{
			if (len + 1 > t.size)
			{
				ft_putstr("\n\r");
				t.size = ft_winsize();
				b = 0;
			}
			b != 0 && t.slt[i] == 1 ?
			ft_putlenstr_fd(len - ft_strlen(av[i]), " ", 1) : 0;
			t.slt[i] == 1 ? ft_putstr(av[i]) : 0;
			t.slt[i] == 1 ? b = 1 : 0;
			t.size -= (len + 1);
		}
	}
}
