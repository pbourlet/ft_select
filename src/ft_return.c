/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:59:25 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 14:02:53 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

void		ft_return(t_slt *t)
{
	while (t->l)
	{
		ft_putstr_fd(tgetstr("up", NULL), 0);
		t->l--;
	}
	ft_putstr_fd(tgetstr("cr", NULL), 0);
	t->size = ft_winsize();
}
