/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:27:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/05/03 18:57:19 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "../libft/includes/libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>

# define E_2FWARG "too few arguments"
# define E_NOMEM "No memory allowed"

void	ft_select_disp(int ac, char **av);
void	ft_underling(void);
void	ft_no_underling(void);

char	*ft_del(char *buff, int *i);

int		ft_select_error(char *prg, char *name, char *erno);
int		ft_putin(int c);
int		ft_move(char *buf, char **av, int ac, int cur);

#endif
