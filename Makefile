# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 09:48:42 by fbenneto          #+#    #+#              #
#    Updated: 2018/02/10 10:29:33 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME=libftprintf.a

############
# COMPILER #
############

CC=gcc
CFLAGS=-Wall -Werror -Wextra

#######
# LIB #
#######

LIB = ar rc

##########
# HEADER #
##########

INC_DIR = ./includes/
INC_NAME = \
	ft_printf_typedef.h\
	ft_printf_header_fc.h\
	ft_printf_d.h\
	ft_printf.h\

INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INC_DIR)

#######
# SRC #
#######

SRC_BUFFER_NAME =\
	ft_buffer.c\
	ft_buffer_2.c\

SRC_BUFFER_DIR = buffer/
SRC_BUFFER = $(addprefix $(SRC_BUFFER_DIR), $(SRC_BUFFER_NAME))

SRC_CONV_NAME =\
	ft_adr.c\
	ft_bin.c\
	ft_fillstr.c\
	ft_unbr.c\
	ft_char.c\
	ft_octal.c\
	ft_hex.c\
	ft_nbr.c\

SRC_CONV_DIR = conv/
SRC_CONV = $(addprefix $(SRC_CONV_DIR), $(SRC_CONV_NAME))

SRC_NAME=\
	$(SRC_BUFFER)\
	$(SRC_CONV)\
	ft_fillforward_annexe.c\
	ft_fillforward.c\
	ft_filldimen.c\
	ft_backward.c\
	ft_get_flags_2.c\
	ft_get_flags.c\
	ft_iswhat_2.c\
	ft_iswhat.c\
	ft_fill_buffer.c\
	ft_init_struct.c\
	ft_singleton.c\
	ft_unicode.c\
	ft_get_int.c\
	ft_strlen.c\
	ft_itoa.c\
	ft_str.c\
	ft_printf.c\

SRC_DIR = ./srcs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

#######
# OBJ #
#######

OBJ_DIR= ./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_NAME))

#########
# MACRO #
#########

NC		= "\\033[0m"
RED		= "\\033[31m"
GREEN	= "\\033[32m"
YELLOW	= "\\033[33m"
BLUE	= "\\033[34m"
MAJENTA	= "\\033[35m"
CYAN	= "\\033[36m"
BOLD	= "\\033[1m"
CHEK	= "\\xE2\\x9C\\x94"
OK		= "$(GREEN)$(CHEK)$(NC)"

#########
# RULES #
#########

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ_DIR)$(SRC_CONV_DIR) $(OBJ_DIR)$(SRC_BUFFER_DIR) $(OBJ)
	@printf "[ft_printf: $@]\n\tdoing ar rc $(BOLD)$(CYAN)$@$(NC)"
	@$(LIB) $@ $(OBJ)
	@printf ' '$(OK)'\n'
	@printf "\tdoing ranlib $(BOLD)$(CYAN)$@$(NC)"
	@ranlib	$@
	@printf ' '$(OK)'\n'

$(OBJ_DIR) :
	@printf "[ft_printf :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $(OBJ_DIR)
	@printf ' '$(OK)'\n'

$(OBJ_DIR)$(SRC_CONV_DIR) : $(OBJ_DIR)
	@printf "[ft_printf :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$(SRC_CONV_DIR)$(NC)"
	@mkdir -p $(OBJ_DIR)$(SRC_CONV_DIR)
	@printf ' '$(OK)'\n'

$(OBJ_DIR)$(SRC_BUFFER_DIR) : $(OBJ_DIR)
	@printf "[ft_printf :$@]\n\tcreating folder $(MAJENTA)$(BOLD)$(SRC_BUFFER_DIR)$(NC)"
	@mkdir -p $(OBJ_DIR)$(SRC_BUFFER_DIR)
	@printf ' '$(OK)'\n'

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE) $(NUMJOBS)
	@printf "\tcompile $(BOLD)$(YELLOW)$@$(NC) "
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@printf $(OK)'\n'

clean : $(OBJ_DIR)
	@printf "[ft_printf: $@]\n\trm all $(BOLD)$(RED) obj file$(NC)"
	@rm -rf $(OBJ_DIR)
	@printf ' '$(OK)'\n'

naelc :
	@printf "[ft_printf: $@] rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)'\n'

norme : $(SRC) $(INCLUDE)
	@printf "[ft_printf: $@]\n\tchecking\n"
	@norminette $^

fclean : clean
	@printf "[ft_printf: $@]\n\trm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)'\n'

proper :
	@make -C ./ all
	@make -C ./ clean

re :
	@make -C ./ fclean
	@make -C ./ all

.PHONY: proper re norme all fclean clean
