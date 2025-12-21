CC=gcc
CFLAGS=-Wall -g
TARGET=student_manage
SRCS=main.c src/*.c
OBJS=$(SRCS:.c=.o)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
clean:
	rm -f $(OBJS) $(TARGET)


