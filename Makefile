# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 15:18:40 by yichoi            #+#    #+#              #
#    Updated: 2022/07/08 17:37:31 by yichoi           ###   ########.fr        #
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
			  ./gnl/get_next_line.h	\
			  ./checker.h

SRCS		=	push_swap.c					\
				push_swap_utils.c			\
				push_swap_sort.c			\
				push_swap_sort_utils.c			\
				push_swap_sort_utils2.c			\
				push_swap_sort_lis.c			\
				check_integer.c				\
				str_enqueue.c				\
				option_swap.c				\
				option_push.c				\
				option_rotate.c				\
				option_reverse_rotate.c		\
				option_tool.c

SRCS_BN		=	checker.c					\
				checker_utils.c					\
				checker_check_integer.c				\
				checker_option_push.c				\
				checker_option_swap.c				\
				checker_option_rotate.c				\
				checker_option_reverse_rotate.c			\
				checker_option_tool.c				\
				checker_parse.c					\
				checker_sort_lis.c				\
				checker_str_enqueue.c			\
				./gnl/get_next_line.c		\
				./gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
	A_OBJS = $(OBJS_BONUS)
	NAME = $(BNS_NAME)
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
	$(RM) $(RMFLAGS) $(NAME) $(BNS_NAME)
	@make fclean -C $(LIBFT)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 $(BNS_NAME)
