/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_underling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:31:15 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 16:53:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_underling(void)
{
	char *tmp;

	tmp = tgetstr("us", NULL);
	tputs(tmp, 0, &ft_putin);
}
