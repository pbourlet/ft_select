/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:44:15 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 14:01:38 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/select.h"

static void	ft_color_set(struct stat statis)
{
	if ((S_ISVTX & statis.st_mode) && (S_IXOTH & statis.st_mode) &&
			S_IWOTH & statis.st_mode)
		ft_putstr_fd("\033[42m\033[30m", 0);
	else if (S_ISDIR(statis.st_mode) && S_IRUSR & statis.st_mode &&
			S_IWUSR & statis.st_mode && S_IXUSR & statis.st_mode &&
			S_IRGRP & statis.st_mode && S_IWGRP & statis.st_mode &&
			S_IXGRP & statis.st_mode && S_IROTH & statis.st_mode &&
			S_IWOTH & statis.st_mode && S_IXOTH & statis.st_mode)
		ft_putstr_fd("\033[43m\033[30m",0);
	else if (S_ISDIR(statis.st_mode))
		ft_putstr_fd("\033[36;01m", 0);
	else if (S_ISBLK(statis.st_mode))
		ft_putstr_fd("\033[46m\033[34m", 0);
	else if (S_ISCHR(statis.st_mode))
		ft_putstr_fd("\033[43m\033[34m", 0);
	else if (S_ISLNK(statis.st_mode))
		ft_putstr_fd("\033[35m", 0);
	else if (S_ISFIFO(statis.st_mode))
		ft_putstr_fd("\033[33m", 0);
	else if (S_ISSOCK(statis.st_mode))
		ft_putstr_fd("\033[36m", 0);
	else if (S_IXOTH & statis.st_mode || S_IXGRP & statis.st_mode
			|| S_IXUSR & statis.st_mode)
		ft_putstr_fd("\033[31m", 0);
}

void		ft_color(void)
{
	struct stat statis;

	g_t.slt[g_t.i] == 1 ? ft_putstr_fd(tgetstr("mr", NULL), 0) : 0;
	g_t.i == g_t.cur ? ft_putstr_fd(tgetstr("us", NULL), 0) : 0;
	if (lstat(g_t.sav[g_t.i], &statis) >= 0)
		ft_color_set(statis);
}
