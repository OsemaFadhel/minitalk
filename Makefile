# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:26:45 by ofadhel           #+#    #+#              #
#    Updated: 2023/03/20 19:34:12 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
PRINTF = libftprintf.a
C_FILE =	client.c
S_FILE =	server.c
SRCC = $(C_FILE)
SRCS = $(S_FILE)
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf
all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)

clean :
		@make clean -C printf
		${RM} ${OBJC}
		${RM} ${OBJS}
	
fclean : clean
		@make fclean -C printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all bonus clean fclean re
