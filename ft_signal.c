/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:29:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/12 14:47:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_signal(int sig)
{
	(void)sig;
	tputs(tgetstr("cl", NULL), 0, ft_putin);
	ft_print(&g_t, g_t.sav, g_t.wlen);
}
