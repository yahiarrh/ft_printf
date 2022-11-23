# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:11:34 by yrrhaibi          #+#    #+#              #
#    Updated: 2022/11/22 23:33:24 by yrrhaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBS = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c ft_printf_hlp.c

OBJS = $(SRC:.c=.o)

RM 	= rm -rf

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $?

%.o : %.c $(LIBS)
	$(CC) $(CFLAGS) -c $< 

clean :
	$(RM) $(OBJS)


fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re