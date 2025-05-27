LIB_NAME = libasm.a
LIB_SRC =	ft_strlen.s
		ft_strcpy.s
		ft_strcmp.s
		ft_write.s
		ft_read.s
		ft_strdup.s

LIB_OBJ = $(LIB_SRC:.s=.o)

ASM = nasm
ASM_FLAGS = -f elf64 -g

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

TEST_NAME = tester
TEST_SRC = main.c

all: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJ)
	ar rcs $@ $^

%.o: %.s
	$(ASM) $(ASM_FLAGS) $< -o $@

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) -o $(TEST_NAME)
	@echo "\033[32mCompiled test binary: ./$(TEST_NAME)\033[0m"

clean:
	rm -f $(LIB_OBJ)

fclean: clean
	rm -f $(LIB_NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean
.SILENT: