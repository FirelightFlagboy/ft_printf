# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    only_script.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:40:28 by fbenneto          #+#    #+#              #
#    Updated: 2017/12/20 10:09:08 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

flags=0
INCLUDE_DIR=../includes/
echo $0
parsed_options=$(
	getopt :wp "$@"
)
tmp=`getopt :w "$@"`
echo $tmp
eval "set -- $parsed_options"
while [ "$#" -gt 0 ]; do
	case $1 in
	(-w) flags=2;
	shift;;
	(-p) flags=1;
	shift;;
	(--) shift;
	break;;
	(*) exit 1 # should never be reached.
	esac
done
make -j3 ../libftprintf.a
case $flags in
	(0) echo "max flag";
	gcc -Wall -Werror -Wextra -o test_only ../libftprintf.a\
	./main_test_only.c -I $INCLUDE_DIR
	;;
	(1) echo "min flags";
	gcc -o test_only ../libftprintf.a ./main_test_only.c -I $INCLUDE_DIR
	;;
	(2) echo "no flags";
	gcc -w -o test_only ../libftprintf.a ./main_test_only.c -I $INCLUDE_DIR
	;;
esac

if [ $# -eq 0 ]
then
	./test_only
else
	./test_only ${*: 1}
fi
