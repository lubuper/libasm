LIB_NAME = lib/libasm.a
LIB_SRC =	src/ft_strlen.s \
	src/ft_strcpy.s \
	src/ft_strcmp.s \
	src/ft_write.s \
	src/ft_read.s \
	src/ft_strdup.s

OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

LIB_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(LIB_SRC:.s=.o)))

ASM = nasm
ASM_FLAGS = -f elf64 -g

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

TEST_NAME = tester
TEST_SRC = main.c

all: $(LIB_DIR) $(OBJ_DIR) $(LIB_NAME)
	@echo "\033[32mCompiled library\033[0m"

$(LIB_DIR) $(OBJ_DIR) $(BIN_DIR):
	@echo creating folders
	mkdir -p $@

$(LIB_NAME): $(LIB_OBJ) | $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: src/%.s | $(OBJ_DIR)
	$(ASM) $(ASM_FLAGS) $< -o $@

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) -o $(TEST_NAME)
	@echo "\033[32mCompiled test binary: ./$(TEST_NAME)\033[0m"

clean:
	rm -rf $(OBJ_DIR) $(TEST_NAME)

fclean: clean
	rm -rf $(LIB_DIR) $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re test
.SILENT:
