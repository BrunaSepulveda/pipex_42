NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT_INC   = $(LIBFT_DIR)/includes

INCLUDES    = -I. -I$(LIBFT_INC)

FILES	= ft_split.c ft_strlcpy.c ft_strlen.c ft_strdup.c ft_substr.c ft_strncmp.c ft_strjoin.c ft_memcpy.c ft_strchr.c

OBJ		= $(FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(EXEC): $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(NAME) -o $(EXEC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all