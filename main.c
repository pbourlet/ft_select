/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:21:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 16:50:55 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

int		ft_select_init(struct termios *save_term)
{
	extern char		**environ;
	char			*name_term;
	char			buff[2048];
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL ||
			tgetent(buff, name_term) == -1 || tcgetattr(0, &term) == -1)
		return (0);
	*save_term = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);
	return (1);
}

int		ft_maxlen(char **av)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (av[++i])
		res = (int)ft_strlen(av[i]) > res ? (int)ft_strlen(av[i]) : res;
	return (res);
}

int		main(int ac, char **av)
{
	struct termios	save_term;
	int				len;

	if (ac >= 2)
	{
		len = ft_maxlen(av);
		if (!ft_select_init(&save_term))
			return (0);
		ft_select_disp(ac, av, len);
		tputs(tgetstr("ve", NULL), 1, &ft_putin);
		tcsetattr(0, TCSANOW, &save_term);
	}
	return (0);
}
