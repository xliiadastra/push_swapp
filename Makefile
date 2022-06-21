# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 15:18:40 by yichoi            #+#    #+#              #
#    Updated: 2022/06/14 22:21:42 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BNS_NAME	= checker

LIBFT		= ./libft

LIBFT_LIB	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm
RMFLAGS		= -f

INCLUDES	= ./push_swap.h			\
			  ./gnl/get_next_line.h

SRCS		=	push_swap.c					\
				push_swap_utils.c			\
				push_swap_sort.c			\
				check_integer.c				\
				str_enqueue.c				\
				option_swap.c				\
				option_push.c				\
				option_rotate.c				\
				option_reverse_rotate.c		\
				option_tool.c				\
				./gnl/get_next_line.c		\
				./gnl/get_next_line_utils.c

SRCS_BN		=	

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifndef WITH_BONUS
A_OBJS = $(OBJS) $(OBJS_BONUS)
else
A_OBJS = $(OBJS)
endif

.PHONY : all
all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME) : $(A_OBJS)
	@make -C $(LIBFT) 
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft

.PHONY : clean
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	@make fclean -C $(LIBFT)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 all
