RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME_B = philo_bonus

HEADER_B = ./include/philosophers_bonus.h

INCLUDE_B = ./include

CC = CC
FLAGS = -Wall -Wextra -Werror
			
BON_FILES = ./src/main_bonus.c \
			./src/philoUtils_bonus.c\
			./src/DiningTable_bonus.c\
			./src/philo_bonus.c\
			./src/ft_usleep_bonus.c\
			./src/ft_print_error_bonus.c\
			./src/check_args_bonus.c\

OBJ_B = $(BON_FILES:%bonus.c=%bonus.o)

all : bonus

bonus : $(NAME_B)

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)

%bonus.o : %bonus.c $(HEADER_B)
	@$(CC) -I$(INCLUDE_B) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJ_B)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME_B) *.gch
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus