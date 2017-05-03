/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:23:34 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 12:24:44 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

int		ft_select_error(char *prg, char *name, char *erno)
{
	ft_printf("%s: ", prg);
	!name? 0 : ft_printf("%s: ", name);
	ft_printf("%s\n", erno);
	return (1);
}
