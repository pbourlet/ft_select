/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:02:46 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 15:55:08 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_winsize(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}
