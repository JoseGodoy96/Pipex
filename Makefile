# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 13:04:48 by jgodoy-m          #+#    #+#              #
#    Updated: 2025/09/18 10:26:27 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = pipex

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src
LIBFT_DIR = ./libft

# Source files and object files
SRC = 	$(SRC_DIR)/pipex.c \
		$(SRC_DIR)/utils.c

OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re 

# Rule that compiles everything by default
all: $(NAME) clean

# Rule to create the pipex
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Convert .c files to .o
%.o: %.c $(INCLUDE_DIR)/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to delete all created object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(GNL_LIB)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
