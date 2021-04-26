NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MLXDYLIB			=	libmlx.dylib

LIBRARIES			=	$(addprefix $(PATH_SRCS), $(LIBCUB3D))\
						$(addprefix $(PATH_LIBFT), $(LIBFT))\
						$(addprefix $(PATH_MLX), $(MLXDYLIB))

PATH_LIBFT			=	srcs/libft/
PATH_MLX			=	srcs/minilibx/

SRCS				=	srcs/main.c\
						srcs/start.c\
						srcs/tools.c\
						srcs/error_manager.c\
						srcs/get_next_line/get_next_line.c\
						srcs/get_next_line/get_next_line_utils.c\
						srcs/parsing/parser.c\
						srcs/parsing/p_resolution.c\
						srcs/parsing/p_textures.c\
						srcs/parsing/p_north_texture.c\
						srcs/parsing/p_south_texture.c\
						srcs/parsing/p_east_texture.c\
						srcs/parsing/p_west_texture.c\
						srcs/parsing/p_sprite_texture.c\
						srcs/parsing/p_colors.c\
						srcs/parsing/p_map.c

HEADERS				=	srcs/header_cub3d.h\
						srcs/libft/header_libft.h\
						srcs/get_next_line/get_next_line.h\
						srcs/minilibx/mlx.h

#INC_HEADERS			=	$(addprefix -I, $(HEADERS))

OBJS				=	$(SRCS:.c=.o)

CUB3D_HEADER		=	srcs/header_cub3d.h

CFLAGS				=	-Wall -Wextra -Werror

COMP				=	clang

RM					=	rm -rf

#$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

%.o:				%.c $(HEADERS)
					$(COMP) $(CFLAGS) -I $(MLX_PATH) -c $< -o $@
					$(COMP) $(CFLAGS) -I $(HEADERS) $(LIBRARIES) -c $< -o $@

################################################################################
# compiler cc au lieu de $(COMP)
# si tu touch un fichier de la libft, il ne faut pas avoir besoin de faire
# make re, pour l'instant ce serait le cas selon Nico
################################################################################

all:			
				$(MAKE) -C $(PATH_MLX)
				mv $(PATH_MLX)$(MLXDYLIB) .
				$(MAKE) $(NAME)

$(LIBCUB3D) :	$(PATH_SCRS) $(PATH_PARS_SRCS)
				ar rcs $(LIBCUB3D) $(PATH_SCRS) $(PATH_PARS_SRCS)\
					$(addprefix $(PATH_SRCS), $(CUB3D_HEADER))

$(NAME):		$(LIBCUB3D)
				$(MAKE) -C $(PATH_LIBFT)
#				$(MAKE) -C $(MLX_PATH)
				$(COMP) $(CFLAGS) -framework OpenGL -framework AppKit\
					-L $(MLX_PATH) -l $(MLX_PATH) $(LIBRARIES)\
					-I $(MLX_PATH) main.c -o $(NAME)
################################################################################
# attention a OpenGL qui normalement correspond a la minilibx non beta
################################################################################

clean:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(PATH_LIBFT)
				$(MAKE) clean -C $(PATH_MLX)

fclean:			clean
#				$(RM) $(NAME)
#				$(RM) $(LIBFT)
				$(RM) ./$(PATH_MLX)/$(MLXDYLIB)
				$(RM) ./$(PATH_MLX)/*.o
				$(RM) ./$(PATH_MLX)/*.swiftmodule
				$(RM) ./$(PATH_MLX)/*.swiftdoc

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
