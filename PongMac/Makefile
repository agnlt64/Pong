# compiler
CC := g++

# flags
CFLAGS := `pkg-config --libs --cflags raylib` -std=c++20

# headers
HDRS := 

# sources files
SRCS := src/*.cpp

# objects files
OBJS := $(SRCS:.c=.o)

# executable
EXEC := pong

# default config
all: $(EXEC)

# build
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

.PHONY: all clean