# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:26:45 by ofadhel           #+#    #+#              #
#    Updated: 2023/04/09 19:22:18 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
C_FILE =	client.c ft_printf.c ft_puthex.c ft_putnbrs.c ft_putchars.c
S_FILE =	server.c ft_printf.c ft_puthex.c ft_putnbrs.c ft_putchars.c

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
RM = rm -rf ../*
all:	${RM} $(NAMEC) $(NAMES)

$(NAMEC) : $(C_FILE)
		$(CC) $(CFLAGS) -o $(NAMEC) $(C_FILE)
$(NAMES) : $(S_FILE)
		$(CC) $(CFLAGS) -o $(NAMES) $(S_FILE)

clean :
		${RM} ${OBJC}
		${RM} ${OBJS}
	
fclean : clean
		${RM} $(NAMEC)
		${RM} $(NAMES)

re : fclean all
