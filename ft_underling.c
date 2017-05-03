/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_underling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:15 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 18:37:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_underling(void)
{
	char *tmp;

	tmp = tgetstr("us", NULL);
	tputs(tmp, 1, &ft_putin);
}

void	ft_no_underling(void)
{
	char *tmp;

	tmp = tgetstr("ue", NULL);
	tputs(tmp, 1, &ft_putin);
}
