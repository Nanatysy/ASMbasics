NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCO = $(SRCS:%.s=%.o)

all: $(NAME)

$(NAME): $(SRCO)
	ar rcs $(NAME) $^

%.o: %.s
	nasm -fmacho64 $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
