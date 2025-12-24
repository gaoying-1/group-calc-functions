CC=gcc
CFLAGS=-Wall -g
TARGET=student_manage
OBJS=main.o manage.o
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f  $(TARGET) $(OBJS)


