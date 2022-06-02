# compiler
CC := g++

# flags
CFLAGS := `pkg-config --libs --cflags raylib` -std=c++20 -o pong

# headers
HDRS := 

# sources files
SRCS := src/*.cpp

# objects files
OBJS := $(SRCS:.c=.o)

# executable
EXEC := game

# default config
all: $(EXEC)

# build
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

#recipe for building object files
# $(OBJS): $(@:.o=.c) $(HDRS) Makefile
# 	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean