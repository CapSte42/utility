NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = get_next_line.c \
    get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = get_next_line_bonus.c \
    get_next_line_utils_bonus.c \

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS) 

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

turbo: all clean

re: fclean all

.PHONY: all clean fclean re bonus