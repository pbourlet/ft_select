/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:21:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/23 15:18:54 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

int			ft_select_init(struct termios *save_term)
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
	term.c_cc[VTIME] = 1;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);
	return (1);
}

static int	ft_maxlen(char **av)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (av[++i])
		res = (int)ft_strlen(av[i]) > res ? (int)ft_strlen(av[i]) : res;
	return (res);
}

static void ft_sigtest(void)
{
	signal(SIGWINCH, ft_signal);
	signal(SIGINT, ft_sigstop);
	signal(SIGTSTP, ft_sigsusp);
	signal(SIGCONT, ft_restor);
}

int			main(int ac, char **av)
{
	int				len;

	if (ac > 512)
		ft_putstr_fd("too much choices\n", 2);
	else if (ac >= 2)
	{
		ft_sigtest();
		len = ft_maxlen(av);
		if (!ft_select_init(&(g_t.save_term)))
			return (0);
		ft_putstr_fd(tgetstr("ti", NULL), 0);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ft_select_disp(ac, av, len);
		ft_putstr_fd(tgetstr("ve", NULL), 0);
		tcsetattr(0, TCSANOW, &(g_t.save_term));
	}
	return (0);
}
