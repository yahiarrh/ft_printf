# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:11:34 by yrrhaibi          #+#    #+#              #
#    Updated: 2022/11/22 00:14:27 by yrrhaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBS = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c ft_printf_hlp.c

OBJ = $(SRC:.c=.o)

RM 	= rm -rf

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

$(NAME) : $(OBJS)
	$(AR) $@ $?

$(OBJS) : $(SRC) $(LIBS)
	cc $(CFLAGS) -c $<

all : $(NAME)

clean :
	$(RM) $(OBJS)


fclean : clean
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re
	