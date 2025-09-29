NAME = fdf

CC = cc

SRCS = main.c

C_BONUS = 

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $@ $^
%.o:%.c
	$(CC) $(CFLAGS) 