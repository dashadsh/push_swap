# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:15:21 by dgoremyk          #+#    #+#              #
#    Updated: 2022/10/29 10:56:50 by dgoremyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

SRC = utils_atoi.c utils_final_rotation.c \
	utils_input.c utils_input2.c push_swap.c utils_cost_calculation.c \
	utils_ll.c utils_triplesort.c utils_instructions.c \
	utils_instructions2.c utils_indexing.c utils_positions.c \
	utils_push_all_to_b.c utils_prepare.c

OBJ = $(SRC:.c=.o)

# gcc -o option flag:
# Write the build output to an output file.
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re