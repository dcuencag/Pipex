NAME            = pipex

# Directories
LIBFT_DIR       = ./libft
OBJ_DIR         = obj/

# Files
LIBFT           = $(LIBFT_DIR)/libft.a

SRCS            = src/main.c

OBJS            = $(SRCS:%.c=$(OBJ_DIR)%.o)

# Compiler and flags
CC              = cc
CFLAGS          = -Wall -Werror -Wextra
INCLUDES        = -I. -I$(LIBFT_DIR)
RM              = rm -f

# Output
all:
	@echo "\033[1;35m==============================\033[0m"
	@echo "\033[1;31m→ Checking build for pipex...\033[0m"
	@echo "\033[1;35m==============================\033[0m"
	@if [ ! -f $(NAME) ]; then \
		echo "\033[1;35m====================\033[0m"; \
		echo "\033[1;34m→ Building pipex...\033[0m"; \
		echo "\033[1;35m====================\033[0m"; \
	fi
	@$(MAKE) $(NAME)
	@echo "\033[1;35m=====================================\033[0m"
	@echo "\033[1;32m✓ pipex build completed successfully\033[0m"
	@echo "\033[1;35m=====================================\033[0m"

$(NAME): $(LIBFT) $(OBJS)
	@echo "\033[1;35m====================\033[0m"
	@echo "\033[1;34m→ Linking pipex\033[0m"
	@echo "\033[1;35m====================\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):

	@if [ ! -f $(LIBFT) ]; then \
		make -C $(LIBFT_DIR); \
	else \
		echo "\033[1;32m✓ Libft already up to date\033[0m"; \
	fi

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[1;36m→ Compiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[1;35m===========================\033[0m"
	@echo "\033[1;33m→ Cleaning object files...\033[0m"
	@echo "\033[1;35m===========================\033[0m"
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "\033[1;35m==========================\033[0m"
	@echo "\033[1;33m→ Cleaning executables...\033[0m"
	@echo "\033[1;35m==========================\033[0m"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re