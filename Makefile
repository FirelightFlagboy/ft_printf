# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 09:48:42 by fbenneto          #+#    #+#              #
#    Updated: 2017/12/29 11:26:53 by fbenneto         ###   ########.fr        #
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

SRC_DIR = ./srcs/
SRC_NAME=\
	ft_fillforward_annexe.c\
	ft_fillforward.c\
	ft_filldimen.c\
	ft_backward.c\
	ft_buffer_2.c\
	ft_buffer.c\
	ft_get_flags_2.c\
	ft_get_flags.c\
	ft_iswhat_2.c\
	ft_iswhat.c\
	ft_fill_buffer.c\
	ft_init_struct.c\
	ft_singleton.c\
	ft_unicode.c\
	ft_get_int.c\
	ft_fillstr.c\
	ft_strlen.c\
	ft_itoa.c\
	ft_adr.c\
	ft_bin.c\
	ft_char.c\
	ft_hex.c\
	ft_unbr.c\
	ft_nbr.c\
	ft_octal.c\
	ft_str.c\
	ft_printf.c\

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

$(NAME) : $(OBJ_DIR) $(OBJ)
	@printf "\n[ft_printf] doing ar rc $(BOLD)$(CYAN)$@$(NC)"
	@$(LIB) $@ $(OBJ)
	@printf '\t'$(OK)'\n'
	@printf "[ft_printf] doing ranlib $(BOLD)$(CYAN)$@$(NC)"
	@ranlib	$@
	@printf '\t'$(OK)'\n'

$(OBJ_DIR) :
	@printf "[ft_printf] creating folder $(MAJENTA)$(BOLD)obj$(NC)"
	@mkdir -p $(OBJ_DIR)
	@printf '\t\t'$(OK)'\n'

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE) $(NUMJOBS)
	@for ((i=0; i<60; i++))\
		do printf ' ';\
	done;
	@printf "\r\033[0m[ft_printf] compile $(BOLD)$(YELLOW)%-20s" "$<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@printf $(NC)$(OK)'\r'

clean : $(OBJ_DIR)
	@printf "[ft_printf] rm all $(BOLD)$(RED) obj file$(NC)"
	@rm -rf $(OBJ_DIR)
	@printf '\t\t'$(OK)'\n'

naelc :
	@printf "[ft_printf] rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

norme : $(SRC) $(INCLUDE)
	@printf "checking\n"
	@norminette $^

fclean : clean
	@printf "[ft_printf] rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

proper :
	@make -C ./ all
	@make -C ./ clean

re :
	@make -C ./ fclean
	@make -C ./ all

.PHONY: proper re norme all fclean clean
