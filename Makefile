CC	:= gcc

RM	:= rm -rf

LDFLAGS += -lm

CFLAGS	+= -Iinclude

SRCS	:= $(shell find src -type f -name "*.c")

OBJS	:= $(SRCS:.c=.o)

NAME	:= emul-mips

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean