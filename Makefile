NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCDIR = src
SRCS = $(SRCDIR)/pipex.c \
	$(SRCDIR)/utils.c \
	$(SRCDIR)/cmd.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
