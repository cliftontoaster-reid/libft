NAME = libft.a

# Directories
SRCS_DIR = ./
INCLUDES_DIR = ./

# Source files
SRCS =

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean all
	bash scripts/tests.sh

.PHONY: all clean fclean re test
