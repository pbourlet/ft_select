/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 15:18:14 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print_selection(char **av, int *slt)
{
	int i;

	i = 0;
	while (av[++i])
	{
		slt[i] == 1 ? ft_putstr(av[i]) : 0;
		slt[i] == 1 ? ft_putchar(' ') : 0;
	}
}
