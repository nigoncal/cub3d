NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MLXDYLIB			=	libmlx.dylib

DIR_LIBRARIES		=   srcs/libraries/

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

CFLAGS				=	-Wall -Wextra -Werror -g3

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
#				ici il te faut les dependances de all
#				c'est a dire les choses dont tu as
#				besoin pour crer les fichiers
#				finaux que ton projet va utiliser pour
#				s'executer.
#				Regardes le Makefile de guhernan pour ca
#				Tu as besoin de :
#								  - cub3d (executable) > c'etait bien la
#								  						 variable EXE
#								  - ^ pour cela :
#								  				   - je ne sais pas, j'ai
#								  				     besoin d'en parler avec
#								  				     Nicolas et Pauline, qui
#								  				     connaissent mieux la
#								  				     minilibx que moi
#								  				   - c'est sur qu'il va me
#								  				     falloir la libft et la
#								  				     dylib de la minilibx
#								  				   - gnl aussi, mais sous
#								  				     quelle forme ? Dans la
#								  				     libft ou seul a cote ? Moi
#								  				     j'aurais dit seul a cote
#								  				     maisje dois en parler avec
#								  				     Nicolas
				$(shell mkdir -p $(DIR_LIBRARIES))
				$(MAKE) -C $(PATH_LIBFT) && mv $(PATH_LIBFT)$(LIBFT) $(DIR_LIBRARIES)
				$(MAKE) -C $(PATH_MLX)
				mv $(PATH_MLX)$(MLXDYLIB) $(DIR_LIBRARIES)
				$(MAKE) $(NAME)

$(LIBCUB3D) :	$(PATH_SCRS) $(PATH_PARS_SRCS)
				ar rcs $(LIBCUB3D) $(PATH_SCRS) $(PATH_PARS_SRCS)\
					$(addprefix $(PATH_SRCS), $(CUB3D_HEADER))

$(NAME):		$(LIBCUB3D)
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
				$(RM) ./$(PATH_MLX)/$(MLXDYLIB) ./$(PATH_MLX)/*.o\
					./$(PATH_MLX)/*.swiftmodule ./$(PATH_MLX)/*.swiftdoc\
					$(DIR_LIBRARIES)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
