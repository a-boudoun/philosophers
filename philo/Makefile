RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = philo

HEADER = ./include/philosophers.h

INCLUDE = ./include

CC = CC
FLAGS = -Wall -Wextra -Werror

MAND_FILES = ./src/main.c \
			./src/philoUtils.c\
			./src/DiningTable.c\
			./src/philo.c\
			./src/ft_usleep.c\
			./src/ft_print_error.c\
			./src/left_or_right.c\
			./src/check_args.c\

OBJ = $(MAND_FILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -I$(INCLUDE) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re