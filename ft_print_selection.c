/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 16:09:28 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print_selection(char **av, int *slt)
{
	int i;

	i = 0;
	tputs(tgetstr("cd", NULL), 0, &ft_putin);
	while (av[++i])
	{
		slt[i] == 1 ? ft_putstr(av[i]) : 0;
		slt[i] == 1 ? ft_putchar(' ') : 0;
	}
}
