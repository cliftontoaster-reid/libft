NAME = libft.a

# Directories
SRCS_DIR = ./
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

BSRC = \
  $(SRCS_DIR)ft_lstadd_back.c \
  $(SRCS_DIR)ft_lstadd_front.c \
  $(SRCS_DIR)ft_lstclear.c \
  $(SRCS_DIR)ft_lstdelone.c \
  $(SRCS_DIR)ft_lstiter.c \
  $(SRCS_DIR)ft_lstlast.c \
  $(SRCS_DIR)ft_lstmap.c \
  $(SRCS_DIR)ft_lstnew.c \
  $(SRCS_DIR)ft_lstsize.c

STATIC_OBJECTS = \
	$(SRCS_DIR)modules/printf/libftprintf.a \

# Object files
OBJS = $(SRCS:.c=.o)
BOBJ = $(BSRC:.c=.o)

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(STATIC_OBJECTS)
	ar rcs $(NAME) $(OBJS) $(STATIC_OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJ)

fclean: clean
	rm -rf $(NAME) modules export

bonus: $(OBJS) $(BOBJ) $(STATIC_OBJECTS)
	ar rcs $(NAME) $(BOBJ) $(OBJS) $(STATIC_OBJECTS)

re: fclean all
bre: fclean bonus

modules/printf/libftprintf.a:
	git clone https://github.com/cliftontoaster-reid/printf modules/printf
	@make -C modules/printf

export: bonus
	mkdir -p export
	cp ./libft.a ./export/
	cp ./libft.h ./export/
	cp ./modules/printf/ft_printf.h ./export/

.PHONY: all clean fclean re bre bonus export test
