CC = g++
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TSTDIR = test

SRCS = GenSort.cpp main.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

TRGT = $(BINDIR)/exe

$(TRGT) : $(OBJS)
	$(CC) -std=c++11 $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -std=c++11 -c $< -Iinclude -o $@

clean:
	rm -rf $(OBJS) $(TRGT) record


