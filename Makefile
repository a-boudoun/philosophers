RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = philo
NAME_B = philo_bonus

HEADER_B = ./philo_bonus_/include/philosophers_bonus.h
HEADER = ./philo_/include/philosophers.h

INCLUDE = ./philo_/include

INCLUDE_B = ./philo_bonus_/include

CC = gcc
FLAGS = -Wall -Wextra -Werror

MAND_FILES = ./philo_/src/main.c \
			./philo_/src/philoUtils.c\
			./philo_/src/DiningTable.c\
			./philo_/src/philo.c\
			./philo_/src/ft_usleep.c\
			./philo_/src/ft_print_error.c\
			./philo_/src/left_or_right.c\
			
BON_FILES = ./philo_bonus_/src/main_bonus.c \
			./philo_bonus_/src/philoUtils_bonus.c\
			./philo_bonus_/src/DiningTable_bonus.c\
			./philo_bonus_/src/philo_bonus.c\
			./philo_bonus_/src/ft_usleep_bonus.c\
			./philo_bonus_/src/ft_print_error_bonus.c\

OBJ = $(MAND_FILES:%.c=%.o)
OBJ_B = $(BON_FILES:%bonus.c=%bonus.o)

all : $(NAME)

bonus : $(NAME_B)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)

%.o : %.c $(HEADER)
	@$(CC) -I$(INCLUDE) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

%bonus.o : %bonus.c $(HEADER_B)
	@$(CC) -I$(INCLUDE_B) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJ) $(OBJ_B)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) $(NAME_B) *.gch
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus