/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:29:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/23 17:47:33 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/select.h"

void	ft_signal(int sig)
{
	(void)sig;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_print(&g_t, g_t.sav, g_t.wlen);
}

void	ft_sigstop(int sig)
{
	(void)sig;
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	tcsetattr(0, TCSANOW, &(g_t.save_term));
	exit(0);
}

void	ft_sigsusp(int sig)
{
	(void)sig;
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	tcsetattr(0, TCSANOW, &(g_t.save_term));
	signal(sig, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void	ft_restor(int sig)
{
	(void)sig;
	ft_select_init(&(g_t.save_term));
	signal(SIGTSTP, &ft_sigsusp);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	ft_print(&g_t, g_t.sav, g_t.wlen);
}
