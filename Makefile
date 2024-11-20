SRCS =	so_long.c ft_utils.c ft_check.c ft_check_utils.c \
		ft_flood_fill.c ft_start_mlx.c 
CC =	cc -g3 #-Wall -Werror -Wextra
DIRLIB = ./libft
DIRLIB2 = ./minilibx-linux

LIBFT = $(DIRLIB)/libft.a
MLXLIB = $(DIRLIB2)/libmlx.a

#INCLUDE = -I/usr/include -Imlx
NAME =	so_long
OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLXLIB)
	$(CC) $(OBJS) $(LIBFT) $(MLXLIB) -lXext -lX11 -o $(NAME)
	@echo "done !"

$(LIBFT) :
	@make -sC $(DIRLIB)

$(MLXLIB) :
	@make -sC $(DIRLIB2)

%.o : %.c
	@$(CC) -c $< -o $@ -Imlx
	#echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@make clean -sC $(DIRLIB2)
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all