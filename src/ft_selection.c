/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:31:16 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 14:03:09 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

void	ft_selection(t_slt *t, char **av)
{
	if (t->i == t->cur && t->bf[0] == 32)
	{
		t->slt[t->i] = !t->slt[t->i];
		ft_memset(t->bf, 0, 4);
		t->bf[0] = 27;
		t->bf[2] = 67;
		if (av[t->i + 1] == NULL)
		{
			t->i = 1;
			ft_return(t);
		}
	}
	t->slt[t->i] == 1 ? ft_putstr_fd(tgetstr("mr", NULL), 0) : 0;
}
