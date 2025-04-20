
SRCS		=	so_long.c				\
				map_loader.c				\
				map_validation.c				\
				image_loader.c			\
				game_actions.c				\
				game_motion.c			\
				memory_management.c				\
				path_finder.c				\

B_SRCS		=	bonus/so_long_bonus.c	\
				bonus/sl_getmap_bonus.c	\
				bonus/sl_errors_bonus.c	\
				bonus/sl_images_bonus.c	\
				bonus/sl_action_bonus.c	\
				bonus/sl_motion_bonus.c	\
				bonus/sl_memory_bonus.c	\
				bonus/sl_finder_bonus.c	\

OBJDIR		= 	obj/

OBJS		= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))
B_OBJS		= 	$(addprefix $(OBJDIR), $(B_SRCS:.c=.o))

NAME		= 	so_long
B_NAME		= 	so_long_bonus

LIBFT		=	./libft
MLX			=	./mlx

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror 

$(OBJDIR)%.o:	%.c
					@mkdir -p $(OBJDIR)
					@mkdir -p $(OBJDIR)/bonus/
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(OBJS) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(B_NAME):		$(B_OBJS)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(B_OBJS) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(B_NAME)

all:			$(NAME) $(B_NAME)

bonus:			$(B_NAME)

clean:
					$(RM) -r $(OBJDIR)
					cd $(LIBFT) && $(MAKE) clean
					cd $(MLX) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(B_NAME)
					cd $(LIBFT) && $(MAKE) fclean
					cd $(MLX) && $(MAKE) fclean

re:				fclean all

norminette :
				@norminette libft
				@norminette bonus
				@norminette *.c
				@norminette *.h	

.PHONY:			all bonus clean fclean re norminette
