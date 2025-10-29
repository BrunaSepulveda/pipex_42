NAME        = pipex
CC          = cc
AR          = ar
ARFLAGS     = rcs
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -Ilibft

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

SRC_DIR     = .
OBJ_DIR     = obj

SRC_FILES   = main.c \
              pipex.c \
              pipex_free.c \
              pipex_handle_cmd.c \
              pipex_handle_files.c \
              pipex_handle_path.c \
			  pipex_utils.c

OBJ_FILES   = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))


.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_A):
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) --no-print-directory; \
	fi

run: $(NAME)
	@if [ "$(ARGS)" = "" ]; then \
		echo "Uso: make run ARGS='infile \"cmd1\" \"cmd2\" outfile'"; \
	else \
		./$(NAME) $(ARGS); \
	fi

clean:
	rm -rf $(OBJ_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean --no-print-directory; fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory; fi

re: fclean all