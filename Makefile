RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = philo

HEADER = ./philo_/include/philosophers.h \


CC = gcc
FLAGS = -Wall -Wextra -Werror

MAND_FILES = ./philo_/src/main.c \
			./philo_/src/philoUtils.c\
			./philo_/src/DiningTable.c\
			./philo_/src/philo.c\
			./philo_/src/ft_usleep.c\
			

OBJ = $(MAND_FILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)



%.o : %.c $(HEADER)
	@$(CC) -I./philo_/include $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus