CC = gcc
ASM = nasm
LIB = libasm.a
SRC = main.c \
test_write_read.c \
test_strcmp.c \
test_strcpy.c \
test_strlen.c 
OBJ = ${SRC:.c=.o}
LIBSRC = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s
LIBOBJ = ${LIBSRC:.s=.o}
CFLAGS = -Wall -Wextra -Werror -g
NAME = tests

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -static -lc -L. -lasm -o $(NAME)

$(LIB): $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

%.o : %.s
	$(ASM) -f elf64 -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(LIB) $(NAME)

re: fclean all

.PHONY: clean fclean re