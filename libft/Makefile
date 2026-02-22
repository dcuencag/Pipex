NAME = libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

INCLUDES = -I. -I$(FT_PRINTF_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c \
	  ft_atoi.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c \
	  ft_atoi_base.c ft_atol.c

OBJ = $(SRC:.c=.o)

all:
	@echo "\033[1;35m==============================\033[0m"
	@echo "\033[1;31m→ Checking build for libft...\033[0m"
	@echo "\033[1;35m==============================\033[0m"
	@if [ ! -f $(NAME) ]; then \
		echo "\033[1;35m====================\033[0m"; \
		echo "\033[1;34m→ Building libft...\033[0m"; \
		echo "\033[1;35m====================\033[0m"; \
	fi
	@$(MAKE) $(NAME)
	@echo "\033[1;35m=====================================\033[0m"
	@echo "\033[1;32m✓ Libft build completed successfully\033[0m"
	@echo "\033[1;35m=====================================\033[0m"

$(NAME): $(OBJ) $(FT_PRINTF)
	@echo "\033[1;35m====================\033[0m"
	@echo "\033[1;34m→ Archiving libft.a\033[0m"
	@echo "\033[1;35m====================\033[0m"
	@ar rcs $(NAME) $(OBJ)
	@cd $(FT_PRINTF_DIR) && ar x ft_printf.a
	@mv $(FT_PRINTF_DIR)/*.o ./
	@ar rcs $(NAME) *.o
	@rm -f *.o

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	@echo "\033[1;36m→ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
