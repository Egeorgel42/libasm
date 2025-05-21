CC = gcc
ASM = nasm
LIB = libasm.a

SRC = main.c \
tests/test_write_read.c \
tests/test_strcmp.c \
tests/test_strcpy.c \
tests/test_strlen.c \
tests/test_strdup.c

OBJ = ${SRC:.c=.o}

LIBSRC = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s

LIBOBJ = ${LIBSRC:.s=.o}
CFLAGS = -Wall -Wextra -Werror -g
NAME = test

all: $(LIB)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -static -z noexecstack -lc -L. -lasm -o $(NAME)

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