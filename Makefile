NAME	= so_long

SRCS	= main.c parsing.c init.c

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

CFLAGS	= -Wall -Werror -Wextra

CC		= clang

RM		= rm -f

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11 mlx/libmlx.a

all:	${NAME}

$(NAME):	${OBJS}
				make -C libft
				make -C ./mlx
				@cp libft/*.h ./includes
				@mv libft/libft.a .
				${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME} ${FL_MLX}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(LIBFT):
			make -C libft
			@cp libft/*.h ./includes
			@mv libft/libft.a .

bonus:	all

clean:
			${RM} ${OBJS}

fclean:		clean
			$(RM) $(NAME) libft.a

re:		fclean all

.PHONY:		all clean fclean re bonus libft