NAME = libasm.a
SRC =	ft_strlen.s
		ft_strcpy.s
		ft_strcmp.s
		ft_write.s
		ft_read.s
		ft_strdup.s

OBJ = $(SRC:.s=.o)

CC = nasm
CFLAGS = -f elf64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.s
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
.SILENT: