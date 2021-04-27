NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MINILIBXDYLIB			=	libmlx.dylib

DIR_LIBRARIES		=   srcs/libraries

LIBRARIES			=	srcs/$(LIBCUB3D) srcs/libft/$(LIBFT) \
						srcs/minilibx$(MINILIBXDYLIB))

PATH_LIBFT			=	srcs/libft
PATH_MINILIBX		=	srcs/minilibx

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

OBJS				=	$(SRCS:.c=.o)

HEADERS				=	$(H_CUB3D)\
						$(H_LIBFT)\
						$(H_GNL)\
						$(H_MINILIBX)

H_CUB3D				=	srcs/header_cub3d.h
H_LIBFT				=	srcs/libft/header_libft.h
H_GNL				=	srcs/get_next_line/get_next_line.h
H_MINILIBX			=	srcs/minilibx/mlx.h

CFLAGS				=	-Wall -Wextra -Werror -g3

COMP				=	clang

RM					=	rm -rf

#$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

%.o:				%.c $(HEADERS)
					$(COMP) $(CFLAGS) -I $(HEADERS) $(LIBRARIES) -c $< -o $@


################################################################################
# compiler clang au lieu de $(COMP)
# si tu touch un fichier de la libft, il ne faut pas avoir besoin de faire
# make re, pour l'instant ce serait le cas selon Nico
################################################################################

all:			$(NAME)	

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




$(LIBCUB3D)	:	$(H_CUB3D) $(OBJS)
				ar rcs $(LIBCUB3D) $(OBJS)\
					$(addprefix $(PATH_SRCS), $(CUB3D_HEADER))

$(NAME)		:	libraries
				$(LIBCUB3D)
#				$(MAKE) -C $(MINILIBX_PATH)
				$(COMP) $(CFLAGS) -framework OpenGL -framework AppKit\
					-L $(MINILIBX_PATH) -l $(MINILIBX_PATH) $(LIBRARIES)\
					-I $(MINILIBX_PATH) main.c -o $(NAME)
################################################################################
# attention a OpenGL qui normalement correspond a la minilibx non beta
################################################################################

libraries	:	$(DIR_LIBRARIES)
				$(shell mkdir -p $(DIR_LIBRARIES))
				$(MAKE) -C $(PATH_LIBFT)
				$(MAKE) -C $(PATH_MINILIBX)
				mv $(PATH_MINILIBX)/$(MINILIBXDYLIB) $(DIR_LIBRARIES)/
				mv $(PATH_LIBFT)/$(LIBFT) $(DIR_LIBRARIES)/



clean		:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(PATH_LIBFT)
				$(MAKE) clean -C $(PATH_MINILIBX)

fclean		:	clean
#				$(RM) $(NAME)
#				$(RM) $(LIBFT)
				$(RM) $(PATH_MINILIBX)/$(MINILIBXDYLIB)
				$(RM) $(PATH_MINILIBX)/*.o
				$(RM) $(PATH_MINILIBX)/*.swiftmodule
				$(RM) $(PATH_MINILIBX)/*.swiftdoc
				$(RM) $(DIR_LIBRARIES)

re			: 	fclean all

.PHONY: all clean fclean re
