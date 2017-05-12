/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:59:25 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/12 14:59:26 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

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
