NAME = libft.a

# Directories
SRCS_DIR = src/
OBJ_DIR ?= target
CACHE_DIR ?= cache
INCLUDES_DIR = ./

# Source files grouped by category
SRCS = \
    $(SRCS_DIR)ctype/ft_isalnum.c \
    $(SRCS_DIR)ctype/ft_isalpha.c \
    $(SRCS_DIR)ctype/ft_isascii.c \
    $(SRCS_DIR)ctype/ft_isdigit.c \
    $(SRCS_DIR)ctype/ft_isprint.c \
    $(SRCS_DIR)ctype/ft_tolower.c \
    $(SRCS_DIR)ctype/ft_toupper.c \
    \
    $(SRCS_DIR)memory/ft_memset.c \
    $(SRCS_DIR)memory/ft_memcpy.c \
    $(SRCS_DIR)memory/ft_memmove.c \
    $(SRCS_DIR)memory/ft_memchr.c \
    $(SRCS_DIR)memory/ft_memcmp.c \
    $(SRCS_DIR)memory/ft_calloc.c \
    $(SRCS_DIR)memory/ft_bzero.c \
    \
    $(SRCS_DIR)conversion/ft_atoi.c \
    $(SRCS_DIR)conversion/ft_itoa.c \
    \
    $(SRCS_DIR)string/ft_strlen.c \
    $(SRCS_DIR)string/ft_strncmp.c \
    $(SRCS_DIR)string/ft_strdup.c \
    $(SRCS_DIR)string/ft_strchr.c \
    $(SRCS_DIR)string/ft_strrchr.c \
    $(SRCS_DIR)string/ft_strnstr.c \
    $(SRCS_DIR)string/ft_strlcpy.c \
    $(SRCS_DIR)string/ft_strlcat.c \
    $(SRCS_DIR)string/ft_strjoin.c \
    $(SRCS_DIR)string/ft_strtrim.c \
    $(SRCS_DIR)string/ft_substr.c \
    $(SRCS_DIR)string/ft_split.c \
    $(SRCS_DIR)string/ft_striteri.c \
    $(SRCS_DIR)string/ft_strmapi.c \
    \
    $(SRCS_DIR)list/ft_lstadd_back.c \
    $(SRCS_DIR)list/ft_lstadd_front.c \
    $(SRCS_DIR)list/ft_lstclear.c \
    $(SRCS_DIR)list/ft_lstdelone.c \
    $(SRCS_DIR)list/ft_lstiter.c \
    $(SRCS_DIR)list/ft_lstlast.c \
    $(SRCS_DIR)list/ft_lstmap.c \
    $(SRCS_DIR)list/ft_lstnew.c \
    $(SRCS_DIR)list/ft_lstsize.c \
    \
    $(SRCS_DIR)fd/ft_putchar_fd.c \
    $(SRCS_DIR)fd/ft_putstr_fd.c \
    $(SRCS_DIR)fd/ft_putendl_fd.c \
    $(SRCS_DIR)fd/ft_putnbr_fd.c \
    $(SRCS_DIR)fd/ft_printf.c	\
    \
    $(SRCS_DIR)utils/itoa.c \
    $(SRCS_DIR)utils/token.c \
    \
    $(SRCS_DIR)interface/hex.c \
    $(SRCS_DIR)interface/nbr.c \
    $(SRCS_DIR)interface/ptr.c \
    $(SRCS_DIR)interface/text.c \

# Object files in target directory
OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror \
		 -O3 -fstack-protector-all \
		 -fsanitize=address -fsanitize=undefined \
		 -pipe -fno-plt -fno-common -g \

INCLUDES = -I$(INCLUDES_DIR) -Iinclude

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(STATIC_OBJECTS)
	ar rcs $(NAME) $(OBJS) $(STATIC_OBJECTS)

$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	$(MAKE) -C tests OBJ_DIR=$(abspath $(OBJ_DIR)/tests) EXT_OBJ=$(abspath $(NAME)) CACHE_DIR=$(abspath $(CACHE_DIR)/tests)
	./tests/libft_test

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) modules export

re: fclean all
bre: fclean bonus

.PHONY: all clean fclean re bre bonus export test