/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:23:44 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/01 20:15:55 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tabclr(char **tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_strclr(tab[i]);
		free(tab[i]);
		i++;
	}
}

char	*ft_resul(char *restab, char *res, int lenb)
{
	char	*tronc[4];
	int		i;

	i = 0;
	tronc[0] = ft_strsub(res, 0, 8);
	tronc[1] = ft_strsub(res, 8, 8);
	tronc[2] = ft_strsub(res, 16, 8);
	tronc[3] = ft_strsub(res, 24, 8);
	restab[i++] = ft_atoibase(tronc[0], 2);
	if (lenb > 7)
		restab[i++] = ft_atoibase(tronc[1], 2);
	if (lenb > 11)
		restab[i++] = ft_atoibase(tronc[2], 2);
	if (lenb > 16)
		restab[i++] = ft_atoibase(tronc[3], 2);
	ft_tabclr(tronc, 4);
	return (restab);
}

char	*ft_trad(char *tab, char *bin, int lenb)
{
	int lent;
	int c;

	c = -1;
	lent = ft_strlen(tab);
	while (lent-- && lenb)
	{
		if (tab[lent] == 'x')
			tab[lent] = bin[--lenb];
	}
	if (ft_strchr(tab, 'x') != NULL)
	{
		while (tab[++c])
		{
			if (tab[c] == 'x')
				tab[c] = '0';
		}
	}
	return (tab);
}

char	*ft_init(int lenb)
{
	char	*tabi;

	tabi = NULL;
	if (lenb <= 7)
		tabi = ft_strdup("0xxxxxxx");
	else if (lenb <= 11)
		tabi = ft_strdup("110xxxxx10xxxxxx");
	else if (lenb <= 16)
		tabi = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else
		tabi = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	return (tabi);
}

char	*ft_bintoa(char *tab)
{
	char	*tabi;
	char	*res;
	int		lenb;
	char	*restab;

	tabi = NULL;
	res = NULL;
	restab = ft_strnew(4);
	lenb = ft_strlen(tab);
	tabi = ft_init(lenb);
	res = ft_trad(tabi, tab, lenb);
	restab = ft_resul(restab, res, lenb);
	ft_strclr(tab);
	free(tab);
	ft_strclr(tabi);
	ft_strclr(res);
	free(tabi);
	return (restab);
}
