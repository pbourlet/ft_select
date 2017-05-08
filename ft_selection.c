/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:31:16 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 16:53:46 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_selection(char *buff, int *slt, int *i)
{
	if (i[0] == i[1] && buff[0] == 32)
	{
		slt[i[0]] = (slt[i[0]] == 1 ? 0 : 1);
		ft_memset(buff, 0, 4);
		buff[0] = 27;
		buff[2] = 67;
	}
	slt[i[0]] == 1 ? tputs(tgetstr("mr", NULL), 0, &ft_putin) : 0;
}
