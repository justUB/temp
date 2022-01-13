CC = g++
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TSTDIR = test

SRCS = ProducerConsumer.cpp CircularQueue.cpp main.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

TRGT = $(BINDIR)/exe

$(TRGT) : $(OBJS)
	$(CC) -std=c++11 $^ -o $@ -lpthread

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -std=c++11 -c $< -Iinclude -o $@ -lpthread

clean:
	rm -rf $(OBJS) $(TRGT)


