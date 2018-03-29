# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 09:48:42 by fbenneto          #+#    #+#              #
#    Updated: 2018/03/29 09:31:00 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########
# TARGET #
##########

NAME=libftprintf.a
MKNAME=ft_printf

############
# COMPILER #
############

CC=clang
CFLAGS=-Wall -Werror -Wextra -O3

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
	ft_printf_global.h\
	ft_printf_d.h\
	ft_float.h\
	ft_printf_header.h\
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

SRC_FLOAT_NAME =\
	float_utils.c\
	ft_fillforward_float.c\
	ft_float.c\

SRC_FLOAT_DIR = float/
SRC_FLOAT = $(addprefix $(SRC_FLOAT_DIR), $(SRC_FLOAT_NAME))

SRC_CONV_NAME =\
	ft_adr.c\
	ft_badconv.c\
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
	$(SRC_FLOAT)\
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
	ft_vprintf.c\

SRC_DIR = ./srcs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

#######
# OBJ #
#######

OBJ_DIR= ./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR), $(OBJ_NAME))

#######
# Dir #
#######

SRC_DIR_NAME =\
	$(SRC_CONV_DIR)\
	$(SRC_FLOAT_DIR)\
	$(SRC_BUFFER_DIR)\

OBJ_DIR_ALL = $(addprefix $(OBJ_DIR), $(SRC_DIR_NAME))

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
CHEK	= "✓"
OK		= "$(GREEN)$(CHEK)$(NC)"

#######
# NOT #
#######

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
		@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = printf "\r\e[K[$(MKNAME):\t%3s%%]" "`expr "\`expr $C '*' 100 / $T\`"`"
endif

#########
# RULES #
#########

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ_DIR_ALL) $(OBJ)
	@$(ECHO)
	@printf " doing ar rc $(BOLD)$(CYAN)$@$(NC)"
	@$(LIB) $@ $(OBJ)
	@printf ' '$(OK)
	@$(ECHO)
	@printf " doing ranlib $(BOLD)$(CYAN)$@$(NC)"
	@ranlib	$@
	@printf ' '$(OK)'\n'

$(OBJ_DIR) :
	@$(ECHO)
	@printf " creating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $(OBJ_DIR)
	@printf ' '$(OK)

$(OBJ_DIR_ALL) :
	@$(ECHO)
	@printf " creating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE) ./Makefile
	@$(ECHO)
	@printf " compile $(BOLD)$(YELLOW)$<$(NC) "
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@printf $(OK)

clean : $(OBJ_DIR)
	@$(ECHO)
	@printf " rm all $(BOLD)$(RED) obj file$(NC)"
	@rm -rf $(OBJ_DIR)
	@printf ' '$(OK)

naelc :
	@$(ECHO)
	@printf " rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)

norme : $(SRC) $(INCLUDE)
	@$(ECHO)
	@printf " checking\n"
	@norminette $^

fclean : clean
	@$(ECHO)
	@printf " rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)

proper :
	@make -C ./ all
	@make -C ./ clean

re :
	@make -C ./ fclean
	@make -C ./ all

print-%:
	@echo '$($*)'

.PHONY: proper re norme all fclean clean
endif
