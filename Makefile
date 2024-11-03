SRCS =	
CC =	cc -g #-Wall -Werror -Wextra
DIRLIB = ./libft
DIRLIB2 = ./minilibx-linux

LIBFT = $(DIRLIB)/libft.a
INCLUDE = ./include
NAME =	so_long
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "done !"

$(LIBFT) :
	@make -sC $(DIRLIB)
	@make -sC $(DIRLIB2)
	

%.o : %.c
	@$(CC) -c $< -o $@
	@echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@rm -f $(OBJS)


fclean : clean
	@rm -f $(NAME) a.out

re : fclean all