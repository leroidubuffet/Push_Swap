# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airyago <airyago@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:33:46 by airyago           #+#    #+#              #
#    Updated: 2023/12/21 20:53:44 by airyago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c bonus

NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -O3 -g3
CFLAGS = -Wall -Wextra -Werror -g

LIBS = /include

RM = rm -f
FILES = push_swap.c \
		check_input.c \
		linked_list_a.c \
		sorting.c \
		moves_swap.c \
		check_list.c \
		sort_four.c \
		sort_three.c \
		sort_two.c \
		moves_rotate.c \
		moves_rev_rotate.c \
		moves_push.c \
		find_best.c \
		check_max_min_b.c \
		check_max_min_a.c \
		checks_best.c \
		free_all.c \
		move_back.c \
		new_min_stack_a.c \
		new_max_stack_a.c \
		new_elem_stack_a.c \
		new_in_stack_b.c \
		ato_utils.c \
		message_utils.c \
		utils.c

FILES_BONUS = checker_bonus.c \
			  ft_check_input_bonus.c \
			  linked_list_a_bonus.c \
			  free_all_bonus.c \
			  linked_list_b_bonus.c \
			  moves_push_bonus.c \
			  moves_rev_rotate_bonus.c \
			  moves_rotate_bonus.c \
			  moves_swap_bonus.c
OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

green = \033[32m
reset = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -O3 -g3 -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAM
