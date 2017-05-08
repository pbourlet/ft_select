/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:27:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/08 16:48:09 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>

void	ft_select_disp(int ac, char **av, int len);
void	ft_underling(void);
void	ft_off(void);
void	ft_selection(char *buff, int *slt, int *i);
void	ft_print_selection(char **av, int *slt);
void	ft_putlenstr_fd(int len, char *content, int fd);

char	*ft_del(char *buff, int *i);

int		ft_select_error(char *prg, char *name, char *erno);
int		ft_putin(int c);
int		ft_move(char *buf, char **av, int ac, int cur);
int		*ft_intset(int *inttab, char c, int len);

#endif
