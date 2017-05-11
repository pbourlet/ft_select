/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:00:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 16:00:54 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_print(int *i, char **av, int len)
{
	i[0] == i[1] ? ft_underling() : 0;
	if (i[4] - len + 1 <= 0)
	{
		ft_putstr_fd("\n\r", 0);
		i[4] = ft_winsize();
		i[5] += 1;
	}
	ft_putstr_fd(av[i[0]], 0);
	ft_off();
	av[i[0]] != NULL ? ft_putlenstr_fd(len - ft_strlen(av[i[0]]), " ", 0) : 0;
	i[0] += 1;
	av[i[0]] != NULL ? i[4] -= (len + 1) : 0;
}
