/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:49:16 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 19:41:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

char	*ft_del(t_slt *t)
{
	char *str;

	ft_memset(t->bf, 0, 4);
	t->i = 1;
	str = tgetstr("cd", NULL);
	tputs(str, 1, &ft_putin);
	t->bf[0] = 27;
	t->bf[2] = 67;
	t->slt[t->cur] = 0;
	return (NULL);
}
