/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/02 15:19:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print_selection(char **av, t_slt t)
{
	int i;
	int b;

	i = 0;
	b = 0;
	ft_putstr_fd(tgetstr("te", NULL), 0);
	while (av[++i])
	{
		t.slt[i] == 1 && b > 0 ? ft_putchar(' ') : 0;
		t.slt[i] == 1 ? ft_printf("%s", av[i]) : 0;
		t.slt[i] == 1 ? b++ : 0;
	}
}
