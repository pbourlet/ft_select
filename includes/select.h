/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:27:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/11 20:19:53 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef struct	s_slt
{
	char		bf[4];
	int			slt[512];
	int			i;
	int			cur;
	int			l;
	int			sac;
	int			size;
}				t_slt;

int				g_signo;

void			ft_select_disp(int ac, char **av, int len);
void			ft_underling(void);
void			ft_off(void);
void			ft_selection(t_slt *t, char **av);
void			ft_print_selection(char **av, t_slt t, int len);
void			ft_putlenstr_fd(int len, char *content, int fd);
void			ft_print(t_slt *t, char **av, int len);
void			ft_signal(int sig);

void			ft_return(t_slt *t);

char			*ft_del(t_slt *t);

int				ft_putin(int c);
int				ft_move(t_slt *t, char **av);
int				ft_winsize(void);

#endif
