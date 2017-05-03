/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:23:14 by pbourlet          #+#    #+#             */
/*   Updated: 2017/04/03 15:34:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	while (l != 0)
	{
		if (s[l] != c)
			l--;
		if (s[l] == c)
			return ((char *)s + l);
	}
	return (NULL);
}
