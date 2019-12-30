# CC = gcc -std=c99
CC = gcc

CFLGAS += -std=c99
CFLAGS += -D TEST
CFLAGS += -g
CFLAGS += -Wall
# CFLAGS += -fsanitize=address

OBJ_PATH = .
BIN_PATH = .
SRC_PATH = ./c

IDIR = .
INC += -I$(IDIR)

TARGET = $(BIN_PATH)/a 
# ifeq ($(OS),Windows_NT)
# 	TARGET_NAME := $(addsuffix .exe,$(TARGET_NAME))
# endif

C_SRCS += test.c
OBJ := $(patsubst %.c,%.o,$(filter %.c,$(C_SRCS)))


$(TARGET) : $(OBJ_PATH)/$(OBJ)
	@ $(CC) $(INC) $(CFLAGS)  $(OBJ)  -o $(TARGET)

$(OBJ): %.o : %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	@-rm *.exe
	@-rm *.o
