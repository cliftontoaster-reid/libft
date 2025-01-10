NAME = libft.a

# Directories
SRCS_DIR = ./
OBJ_DIR = target
INCLUDES_DIR = ./

# Source files
SRCS = \
	$(SRCS_DIR)ft_atoi.c \
	$(SRCS_DIR)ft_bzero.c \
	$(SRCS_DIR)ft_calloc.c \
	$(SRCS_DIR)ft_isalnum.c \
	$(SRCS_DIR)ft_isalpha.c \
	$(SRCS_DIR)ft_isascii.c \
	$(SRCS_DIR)ft_isdigit.c \
	$(SRCS_DIR)ft_isprint.c \
	$(SRCS_DIR)ft_itoa.c \
	$(SRCS_DIR)ft_memchr.c \
	$(SRCS_DIR)ft_memcmp.c \
	$(SRCS_DIR)ft_memcpy.c \
	$(SRCS_DIR)ft_memmove.c \
	$(SRCS_DIR)ft_memset.c \
	$(SRCS_DIR)ft_putchar_fd.c \
	$(SRCS_DIR)ft_putendl_fd.c \
	$(SRCS_DIR)ft_putnbr_fd.c \
	$(SRCS_DIR)ft_putstr_fd.c \
	$(SRCS_DIR)ft_split.c \
	$(SRCS_DIR)ft_strchr.c \
	$(SRCS_DIR)ft_strdup.c \
	$(SRCS_DIR)ft_striteri.c \
	$(SRCS_DIR)ft_strjoin.c \
	$(SRCS_DIR)ft_strlcat.c \
	$(SRCS_DIR)ft_strlcpy.c \
	$(SRCS_DIR)ft_strlen.c \
	$(SRCS_DIR)ft_strmapi.c \
	$(SRCS_DIR)ft_strncmp.c \
	$(SRCS_DIR)ft_strnstr.c \
	$(SRCS_DIR)ft_strrchr.c \
	$(SRCS_DIR)ft_strtrim.c \
	$(SRCS_DIR)ft_substr.c \
	$(SRCS_DIR)ft_tolower.c \
	$(SRCS_DIR)ft_toupper.c \
	$(SRCS_DIR)ft_lstadd_back.c \
	$(SRCS_DIR)ft_lstadd_front.c \
	$(SRCS_DIR)ft_lstclear.c \
	$(SRCS_DIR)ft_lstdelone.c \
	$(SRCS_DIR)ft_lstiter.c \
	$(SRCS_DIR)ft_lstlast.c \
	$(SRCS_DIR)ft_lstmap.c \
	$(SRCS_DIR)ft_lstnew.c \
	$(SRCS_DIR)ft_lstsize.c \
	$(SRCS_DIR)ft_printf.c \
	$(SRCS_DIR)utils/itoa.c \
	$(SRCS_DIR)utils/mem.c \
	$(SRCS_DIR)utils/token.c \
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
		 -pipe -fno-plt -fno-common \

INCLUDES = -I$(INCLUDES_DIR) -Iinclude

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(STATIC_OBJECTS)
	ar rcs $(NAME) $(OBJS) $(STATIC_OBJECTS)

$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) modules export

re: fclean all
bre: fclean bonus

export: $(NAME)
	mkdir -p export
	cp ./libft.a ./export/
	cp ./libft.h ./export/

.PHONY: all clean fclean re bre bonus export test
