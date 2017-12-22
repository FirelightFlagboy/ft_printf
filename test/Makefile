# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 09:48:42 by fbenneto          #+#    #+#              #
#    Updated: 2017/12/20 10:07:23 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############
# COMPILER #
############

CC=gcc
CFLAGS=-Wall -Werror -Wextra

########
# HELP #
########

NAME=$(SRC:.c=)
EXE = ft_printf
#######
# SRC #
#######

SRC=\
	main_printf_flags.c\
	main_testlongchar.c\
	main_test_only.c\
	main_ftprintf.c\
	main_longchar.c\
	main_testhex.c\
	main_printf.c\
	main_stdarg.c\
	main_color.c\
	main_leaks.c\
	main_rtval.c\

################
# HEADER & LIB #
################

PRINTF = libftprintf.a
PRINTF_DIR = ../
FT_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF))
INC_NAME = \
	ft_printf.h
INC_DIR = ../includes/
INCLUDE = $(addprefix $(INC_DIR), $(INC_NAME))
INC = -I $(INCLUDE)

#######
# OBJ #
#######

OBJ=$(SRC:.c=.o)


#########
# MACRO #
#########

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

#########
# RULES #
#########

all : help

ft_printf: main_ftprintf.o $(FT_PRINTF)
	@printf "[test] making the test binary $(CYA)$(BOL)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_test_only : main_test_only.o $(FT_PRINTF)
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

$(FT_PRINTF) :
	@make -C ../ $(PRINTF)

main_leaks : main_leaks.o $(FT_PRINTF)
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_printf : main_printf.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_stdarg : main_stdarg.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_rtval : main_rtval.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_color : main_color.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_testhex : main_testhex.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_testlongchar : main_testlongchar.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_printf_flags : main_printf_flags.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf '\t'$(OK)'\n'

main_printf_no_flags : main_printf_flags.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) -o $@ $^
	@printf '\t'$(OK)'\n'

main_longchar : main_longchar.c ft_convert_base.c ft_itoa.c
	@printf "[test] making $(BOL)$(CYA)$@$(NC)"
	@$(CC) -o $@ $^
	@printf '\t'$(OK)'\n'

clean :
	@printf "rm all\t$(BOL)$(RED)%-20s$(NC)" "obj file"
	@rm -f $(OBJ)
	@printf $(OK)'\n'

fclean : clean
	@printf "rm "
	@for o in $(NAME); do\
		printf "\t$(BOL)$(CYA)%-20s$(NC)" $$o;\
		rm -f $$o; printf $(OK)'\n';\
	done;
	@printf "\t$(BOL)$(CYA)%-20s$(NC)" $(EXE)
	@rm -f $(EXE)
	@printf $(OK)'\n'

proper : all clean

re : fclean all

%.o: %.c $(INCLUDE)
	@printf "\r\033[0K[test] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)
	@printf '\t'$(OK)'\n'

help :
	@printf "You can make one of this binyary :\n"
	@for o in $(OBJ); do\
		printf '\t'$$o'\n' | sed "s/\.o//g";\
	done;

.PHONY: proper re help all $(FT_PRINTF)
