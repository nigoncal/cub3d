NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MINILIBX			=	libmlx.dylib

LIBRARIES			=	$(addprefix $(SRCS_PATH), $(LIBCUB3D))\
						$(addprefix $(LIBFT_PATH), $(LIBFT))\
						$(addprefix $(MINILIBX_PATH), $(MINILIBX))

SRCS_PATH			=	/srcs/
PARS_SRCS_PATH		=	/srcs/parsing/
LIBFT_PATH			=	/srcs/libft/
MINILIBX_PATH		=	/srcs/minilibx/

SRCS				=	start.c\
						tools.c\
						error_manager.c
	
PARS_SRCS			=	parser.c\
						p_resolution.c\
						p_textures.c\
						p_north_texture.c\
						p_south_texture.c\
						p_east_texture.c\
						p_west_texture.c\
						p_sprite_texture.c\
						p_colors.c\
						p_map.c



OBJS				=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))\
						$(addprefix $(PARS_SRCS_PATH), $(PARS_SRCS:.c=.o))

CUB3D_HEADER		=	header_cub3d.h

CFLAGS				=	-Wall -Wextra -Werror

#$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

%.o:			%.c $() $()
				gcc -I $(HEADER) $(LIBRARIES)

all:			$(NAME)
#				$(MAKE) init
#				$(MAKE) $(NAME)

init:	$(MINILIBX)
	$(shell mkdir -p $(PATH_OBJS))

$(LIBCUB3D) :	$(OBJS)
				ar rcs $(LIBCUB3D) $(OBJS)\
					$(addprefix $(SRCS_PATH), $(CUB3D_HEADER))

$(NAME):		$(LIBCUB3D)
				make -C $(LIBFT_PATH)
				make -C $(MINILIBX_PATH)
				gcc $(CFLAGS) $(LIBRARIES) main.c -o $(NAME)

clean:
				rm -rf $(OBJS)
				make clean -C $(LIBFT_PATH)
				make clean -C $(MINILIBX_PATH)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(MINILIBX)
				rm -rf $(LIBFT)
				rm -rf ./$(PATH_MINILIBX)/$(MINILIBX)
				rm -rf ./$(PATH_MINILIBX)/*.o
				rm -rf ./$(PATH_MINILIBX)/*.swiftmodule
				rm -rf ./$(PATH_MINILIBX)/*.swiftdoc

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
