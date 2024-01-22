NAME1        := part1
NAME2	     := part2
CC        := g++
FLAGS    := -Wall -Werror -Wextra
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS1        :=      day01p1.cpp
SRCS2        :=      day01p2.cpp

OBJS1        := $(SRCS1:.c=.o)
OBJS2 	     := $(SRCS2:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f


${NAME1}:	${OBJS1}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME1) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME1} ${OBJS1}
			@echo "$(GREEN)$(NAME1) created[0m ✔️"

${NAME2}:	${OBJS2}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME2) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME2} ${OBJS2}
			@echo "$(GREEN)$(NAME2) created[0m ✔️"

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME1) $(CLR_RMV)objs ✔️"
			@ echo "$(RED)Deleting $(CYAN)$(NAME2) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME1} ${NAME2}
			@ echo "$(RED)Deleting $(CYAN)$(NAME1) $(CLR_RMV)binary ✔️"
			@ echo "$(RED)Deleting $(CYAN)$(NAME2) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
