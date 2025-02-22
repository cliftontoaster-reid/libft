# Library 42

Library 42 is a C library providing a wide range of utility functions—from character and string manipulation to memory management, conversion routines, linked list operations, and formatted output.

## Features

- **Character Functions:**

  - [`ft_isalnum`](src/ctype/ft_isalnum.c)
  - [`ft_isalpha`](src/ctype/ft_isalpha.c)
  - [`ft_isascii`](src/ctype/ft_isascii.c)
  - [`ft_isdigit`](src/ctype/ft_isdigit.c)
  - [`ft_isprint`](src/ctype/ft_isprint.c)
  - [`ft_tolower`](src/ctype/ft_tolower.c)
  - [`ft_toupper`](src/ctype/ft_toupper.c)

- **Memory Functions:**

  - [`ft_memset`](src/memory/ft_memset.c)
  - [`ft_memcpy`](src/memory/ft_memcpy.c)
  - [`ft_memmove`](src/memory/ft_memmove.c)
  - [`ft_memchr`](src/memory/ft_memchr.c)
  - [`ft_memcmp`](src/memory/ft_memcmp.c)
  - [`ft_calloc`](src/memory/ft_calloc.c)
  - [`ft_bzero`](src/memory/ft_bzero.c)

- **Conversion Functions:**

  - [`ft_atoi`](src/conversion/ft_atoi.c)
  - [`ft_itoa`](src/conversion/ft_itoa.c)

- **String Functions:**

  - [`ft_strlen`](src/string/ft_strlen.c)
  - [`ft_strdup`](src/string/ft_strdup.c)
  - [`ft_strchr`](src/string/ft_strchr.c)
  - [`ft_strrchr`](src/string/ft_strrchr.c)
  - [`ft_strncmp`](src/string/ft_strncmp.c)
  - [`ft_strnstr`](src/string/ft_strnstr.c)
  - [`ft_strlcpy`](src/string/ft_strlcpy.c)
  - [`ft_strlcat`](src/string/ft_strlcat.c)
  - [`ft_strjoin`](src/string/ft_strjoin.c)
  - [`ft_strtrim`](src/string/ft_strtrim.c)
  - [`ft_substr`](src/string/ft_substr.c)
  - [`ft_split`](src/string/ft_split.c)
  - [`ft_striteri`](src/string/ft_striteri.c)
  - [`ft_strmapi`](src/string/ft_strmapi.c)

- **Linked List Functions:**

  - [`ft_lstnew`](src/list/ft_lstnew.c)
  - [`ft_lstadd_front`](src/list/ft_lstadd_front.c)
  - [`ft_lstadd_back`](src/list/ft_lstadd_back.c)
  - [`ft_lstclear`](src/list/ft_lstclear.c)
  - [`ft_lstdelone`](src/list/ft_lstdelone.c)
  - [`ft_lstiter`](src/list/ft_lstiter.c)
  - [`ft_lstlast`](src/list/ft_lstlast.c)
  - [`ft_lstmap`](src/list/ft_lstmap.c)
  - [`ft_lstsize`](src/list/ft_lstsize.c)

- **File Descriptor Functions:**

  - [`ft_putchar_fd`](src/fd/ft_putchar_fd.c)
  - [`ft_putstr_fd`](src/fd/ft_putstr_fd.c)
  - [`ft_putendl_fd`](src/fd/ft_putendl_fd.c)
  - [`ft_putnbr_fd`](src/fd/ft_putnbr_fd.c)

- **Formatted Output:**

  - [`ft_printf`](src/fd/ft_printf.c)

- **Utilities:**

  - [`ft_ltoa`](src/utils/itoa.c)
  - Token utilities in [`token.c`](src/utils/token.c)

- **Interface Helpers:**
  - Hexadecimal output ([`ft_puthex`](src/interface/hex.c))
  - Number output ([`ft_putnbr`](src/interface/nbr.c), [`ft_putunbr`](src/interface/nbr.c))
  - Pointer conversion ([`ft_ptrtoa`](src/interface/ptr.c), [`ft_putptr`](src/interface/ptr.c))
  - Text output ([`ft_putchar`](src/interface/text.c), [`ft_putstr`](src/interface/text.c))

## Requirements

- A C compiler (e.g. clang or gcc)
- GNU Make
- [CUnit](https://cunit.sourceforge.net) for unit tests
- _Optional:_ `norminette` for style checking

## Build & Test Instructions

1. **Build the Library:**  
   Run the following command to compile and archive the library into [`libft.a`](libft.a):
   ```sh
   make
   ```
