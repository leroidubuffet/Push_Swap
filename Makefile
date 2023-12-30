# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude -Wextra -Werror -g -fsanitize=address
DEPFLAGS = -MMD -MP

# Source and object directories
SRC_DIR = srcs
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Automatically detect source files and corresponding object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Name of the final executable
TARGET = $(BIN_DIR)/push_swap

# Default target
all: $(TARGET)

# Rule to make the target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

test: re
	rm push_swap
	mv bin/push_swap .
	bash push_swap_test.sh

# Assuming 're' is a rule that rebuilds everything
# If it's not, replace 're' with the appropriate rule

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(DEPS)

# Full clean (clean + remove binary)
fclean: clean
	rm -f $(TARGET)

# Rebuild (full clean + all)
re: fclean all

# Mark 'all' and 'clean' as phony so make doesn't look for files named 'all' and 'clean'
.PHONY: all clean fclean re test
