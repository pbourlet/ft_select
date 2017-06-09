/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlenstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:49:18 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 15:54:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_putlenstr_fd(int len, char *content, int fd)
{
	int i;

	i = content ? ft_strlen(content) : 0;
	ft_putstr_fd(content, fd);
	while (i++ <= len)
		ft_putchar_fd(' ', fd);
}
