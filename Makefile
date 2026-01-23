NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCDIR = src
SRCS =  $(SRCDIR)/pipex.c \
		$(SRCDIR)/utils.c \
		$(SRCDIR)/cmd.c

OBJS = obj

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(NAME) compiled sucessfully"

$(OBJS)/%.o: $(SRCS)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
