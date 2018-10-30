##
## Makefile for  in /home/flavian/PSU/bootstrap/PSU_2016_navy
## 
## Made by Feugueur Flavian
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Mon Jan 30 16:38:22 2017 Feugueur Flavian
## Last update Mon Feb 13 21:59:58 2017 Hugo Tallineau
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c		\
		src/usage.c		\
		src/tools.c		\
		src/tools2.c		\
		src/check_map.c		\
		src/check_map2.c	\
		src/check_map3.c	\
		src/read_map.c		\
		src/my_str_to_wordtab.c	\
		src/exec.c		\
		src/disp_my_pos.c	\
		src/disp.c		\
		src/check_hit.c		\
		src/try_attack.c	\
		src/get_order.c		\
		src/check_win.c		\
		src/get_j2_pid.c	\
		src/receive.c		\
		src/send_signal.c	\
		src/my_sort_array.c	\
		src/do_stuff.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	+=	-I ./include -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)  -L ./lib -lgnl	

clean:
	$(RM) $(OBJ)
	$(RM) $(SRC:.c=.c~)
	$(RM) $(SRC:.c=.c#)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
