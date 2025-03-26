NAME = philo

CC = cc

HEADER = philo.h

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g 

SRC = philo.c \
	parssing.c \
	utilis_1.c \
	utilis_2.c \
	utilis_3.c \
	
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