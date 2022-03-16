TARGET=rush-02
OBJS=func.o logic.o main.o func2.o
FLAG=-Wall -Wextra -Werror

all	:	$(TARGET)

clean	:
	rm -rf *.o
fclean	: clean
	rm -rf $(TARGET)

$(TARGET)	:	$(OBJS)
	gcc -o $(TARGET) $(OBJS)
