SRCS =	test.c
CC =	cc -g #-Wall -Werror -Wextra
DIRLIB = ./libft
DIRLIB2 = ./minilibx-linux
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT = $(DIRLIB)/libft.a
MLXLIB = $(DIRLIB2)/libmlx.a

INCLUDE = -I/usr/include -Imlx
NAME =	so_long
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLXLIB)
	$(CC)  $(OBJS) $(LIBFT) $(MLXLIB) -o $(NAME) 
	@echo "done !"

$(LIBFT) :
	@make -sC $(DIRLIB)
	
$(MLXLIB) :
	make -sC $(DIRLIB2)

%.o : %.c
	$(CC) -c $< -o $@ $(INCLUDE)
	#echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@make clean -sC $(DIRLIB2)

	@rm -f $(OBJS)



fclean : clean
	@rm -f $(NAME) so_long

re : fclean all