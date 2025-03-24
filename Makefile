NAME = philo

CC = cc

HEADER = philo.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g 

SRC = first_file.c \
	parssing.c \
	activities.c \
	utilis_1.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ1)
fclean: clean
	rm -rf $(NAME) 
re : fclean all

.PHONY : clean