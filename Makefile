#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/06 21:39:23 by pbourlet          #+#    #+#             *#
#*   Updated: 2017/06/09 14:26:51 by pbourlet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =	ft_select

LIB	=	-L. ~/libft/libft.a

TCAP =	-L. -ltermcap

INC	=	$(addprefix ~/libft/, \
		includes/libft.h \
		includes/get_next_line.h \
		includes/ft_printf.h \
		ft_printf/ft_printf.h \
		get_next_line/get_next_line.h\
		) \
		includes/select.h \

SRCDIR =	src

OBJDIR =	obj

SLT	=	\
		main.c \
		ft_select_disp.c \
		ft_move.c \
		ft_del.c \
		ft_selection.c \
		ft_print_selection.c \
		ft_putlenstr_fd.c \
		ft_print.c \
		ft_winsize.c \
		ft_signal.c \
		ft_return.c \
		ft_color.c \

OBJ	=	$(SLT:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): dir $(OBJ)
	@make -C ~/libft/
	@gcc -o $(NAME) $(OBJ) $(LIB) $(TCAP)
	@echo "\033[34;01m===== \c"
	@echo "\033[32;01mEXE CREATED\c"
	@echo "\033[0m\033[34;01m   =====\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@gcc -c -Wall -Wextra -Werror -o $@ -c $< -I./includes 
	@echo "\033[34;01m\xE2\x97\x89 \c"
	@echo "\033[37;01m$(notdir $(basename $<))\c"
	@echo "\033[32;01m ✓"
	@echo "\033[0m\c"

dir:
	@mkdir -p $(OBJDIR)

clean:
	@make -C ~/libft/ clean
	@echo "\033[31m===== \c"
	@echo "\033[0m\033[32;01mDIR CLEAN\c"
	@echo "\033[0m\033[31m     =====\033[0m"
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf ~/libft/libft.a
	@echo "\033[31m===== \c"
	@echo "\033[0m\033[32;01mEXE CLEAN\c"
	@echo "\033[0m\033[31m     =====\033[0m"
	@rm -rf $(NAME)

re: fclean all
