/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_disp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:25:49 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 19:22:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_print(char *buff, int *i, int cur, char **av)
{
	*i == cur ? ft_underling() : 0;
	av[*i] != NULL ? ft_putstr(av[*i]) : 0;
	ft_no_underling();
	av[*i] != NULL ? ft_putchar(' ') : 0;
	*i += 1;
	ft_memset(buff, 0, 4);
}

void	ft_select_disp(int ac, char **av)
{
	char	buff[4];
	int		i;
	int		cur;

	ft_memset(buff, 0, 4);
	cur = 1;
	tputs(tgetstr("vi", NULL), 1, &ft_putin);
	while (buff[0] != 10 && cur != -1)
	{
		i = 1;
		while (i < ac && cur != -1)
		{
			if (buff[0] == 127 || (buff[0] == 27 && buff[1] == 91 &&
						buff[2] == 51 && buff[3] == 126))
				av[cur] = ft_del(buff, &i);
			if (buff[0] == 27 && (buff[2] == 68 || buff[2] == 67))
				cur = ft_move(buff, av, ac - 1, cur);
//			else if (buff[0] == 32)
//				ft_selection(buff, av[cur]);
			ft_print(buff, &i, cur, av);
		}
		ft_putchar('\r');
		cur != -1 ? read(0, buff, 4) : 0;
	}
}
