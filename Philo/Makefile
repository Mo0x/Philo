NAME = philo
CC = gcc 
SRCS = ./srcs/main.c \
		./srcs/error.c \
		./srcs/utils0.c \
		./srcs/utils1.c \
		./srcs/parser.c \
		./srcs/init.c	\
		./srcs/thread.c \
		./srcs/watcher.c \
		./srcs/think_eat_sleep.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -g3 -pthread

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re