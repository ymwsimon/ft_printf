NAME	= libftprintf.a

SRCS = ft_printf.c ft_pf_gen_asc.c ft_pf_gen_asc2.c ft_pf_utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

all : $(NAME)

re : clean $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

.PHONY : clean fclean all re $(NAME)
