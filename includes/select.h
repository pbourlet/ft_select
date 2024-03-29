/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:27:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/08 19:55:40 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "../../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/stat.h>

typedef struct		s_slt
{
	char			bf[4];
	int				slt[512];
	int				i;
	int				cur;
	int				l;
	int				sac;
	char			**sav;
	int				size;
	int				wlen;
	int				b;
	struct termios	save_term;
}					t_slt;

t_slt				g_t;

void				ft_select_disp(int ac, char **av, int len);
void				ft_selection(t_slt *t, char **av);
void				ft_print_selection(char **av, t_slt t);
void				ft_putlenstr_fd(int len, char *content, int fd);
void				ft_print(t_slt *t, char **av, int len);
void				ft_sigsize(int sig);
void				ft_sigstop(int sig);
void				ft_sigsusp(int sig);
void				ft_restor(int sig);
void				ft_return(t_slt *t);
void				ft_color(void);
void				ft_testsig(int sig);

char				*ft_del(t_slt *t);

int					ft_move(t_slt *t, char **av);
int					ft_winsize(void);
int					ft_select_init(struct termios *save_term);

#endif
