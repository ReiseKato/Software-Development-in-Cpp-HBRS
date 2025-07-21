NAME=Program
CC=g++
CFLAGS=-Wall -Wextra -std=c++17

all: $(NAME)

$(NAME): main.o VirtualArray.o
	$(CC) $(CFLAGS) -o $(NAME) main.o VirtualArray.o

main.o: main.cc VirtualArray.hh
	$(CC) $(CFLAGS) -c main.cc

VirtualArray.o: VirtualArray.cc VirtualArray.hh
	$(CC) $(CFLAGS) -c VirtualArray.cc

clean:
	rm -f *.o $(NAME)