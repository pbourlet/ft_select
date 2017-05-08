/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:25:49 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 17:22:05 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print(int *i, char **av, int len)
{
	i[0] == i[1] ? ft_underling() : 0;
	ft_putstr_fd(av[i[0]], 0);
	ft_off();
	av[i[0]] != NULL ? ft_putlenstr_fd(len - ft_strlen(av[i[0]]), " ", 0) : 0;
	i[0] += 1;
}

void	ft_modif(char *buff, int *i, int *slt, char **av)
{
	if ((i[0] == i[1] && buff[0] == 32) || slt[i[0]] == 1)
		ft_selection(buff, slt, i);
	if (buff[0] == 27 && (buff[2] == 68 || buff[2] == 67))
		i[1] = ft_move(buff, av, i[3], i[1]);
}

void	ft_to_zero(char *buff, int *slt, int *i, int ac)
{
	ft_memset(buff, 0, 4);
	ft_memset(slt, 0, 2048);
	i[1] = 1;
	i[2] = 2;
	i[3] = ac - 1;
}

void	ft_select_disp(int ac, char **av, int len)
{
	char	buff[4];
	int		i[4];
	int		slt[2048];

	ft_to_zero(buff, slt, i, ac);
//	tputs(tgetstr("vi", NULL), 1, &ft_putin);
	while (!((buff[0] == 27 && buff[2] == 0) || buff[0] == 10) && i[1] != -1)
	{
		while (i[2]--)
		{
			i[0] = 1;
			while (i[0] <= ac && i[1] != -1)
			{
				if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 &&
				buff[2] == 51 && buff[3] == 126))
					av[i[1]] = ft_del(buff, &i[0]);
				ft_modif(buff, i, slt, av);
				ft_print(i, av, len);
			}
			tputs(tgetstr("up", NULL), 0, &ft_putin); //compter le nb de lignes avec winsize
			tputs(tgetstr("cr", NULL), 0, &ft_putin);
		}
		i[2] = 2;
		i[1] != -1 ? read(0, buff, 4) : 0;
	}
	buff[0] != 27 ? ft_print_selection(av, slt) : 0;
}
