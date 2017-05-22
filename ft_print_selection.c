/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/22 18:15:04 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print_selection(char **av, t_slt t)
{
	int i;

	i = 0;
	tputs(tgetstr("te", NULL), 0, &ft_putin);
	while (av[++i])
		t.slt[i] == 1 ? ft_printf("%s ", av[i]) : 0;
}
