CC=gcc
RM=rm -f
CFLAGS=-g -Werror -Wextra -Wall

SRC=src
OBJ=obj
INC=inc

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(INC)/*.h)


BIN=nmap

all:$(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(BIN)