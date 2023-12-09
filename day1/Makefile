CFLAGS := -pthread -Wall
SOURCES := $(wildcard day*.c)
PROGRAMS := $(SOURCES:.c=)
OBJ_DIR := out
OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(OBJ_DIR) $(PROGRAMS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PROGRAMS): %: $(OBJ_DIR)/%.o
	gcc $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJ_DIR)/*.o $(PROGRAMS)

fullclean:
	rm -f $(OBJ_DIR)/*.o $(PROGRAMS)
	rmdir $(OBJ_DIR)
