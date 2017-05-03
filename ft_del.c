/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:49:16 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 19:13:48 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

char	*ft_del(char *buff, int *i)
{
	char *str;

	ft_memset(buff, 0, 4);
	*i = 1;
	str = tgetstr("cd", NULL);
	tputs(str, 1, &ft_putin);
	buff[0] = 27;
	buff[2] = 67;
	return (NULL);
}
