NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
#celui-ci n'est pas liste dans les libraries car il est cree, a la rigueur desplaces le apres
LIBFT				=	libft.a
MINILIBXDYLIB		=	libmlx.dylib


LIBRARIES			=	srcs/$(LIBCUB3D) srcs/libft/$(LIBFT)\
						srcs/minilibx$(MINILIBXDYLIB))

VPATH				=	srcs parsing get_next_line libft minilibx textures\
						libraries $(VSCRS) $(VLIBFT) $(VMINILIBX) $(VPARSING)\
						$(VGNL) $(VLIBRARIES) $(VLIBFT)
# est-ce que libraries est a ajouter ici, vu que c'est un nouveau dir que tu
# crees dans ton Makefile. Je sais pas poruquoi je le sens mal. Testes et tu
# verras

VSRCS				=	srcs
VLIBRARIES			=   srcs/libraries
VLIBFT				=	srcs/libft
VGNL				=	srcs/get_next_line
VMINILIBX			=	srcs/minilibx
VPARSING			=	srcs/parsing
VTEXTURES			=	srcs/textures

SRCS				=	main.c\
						start.c\
						tools.c\
						error_manager.c\

PARSING				=	parser.c\
						p_resolution.c\
						p_textures.c\
						p_north_texture.c\
						p_south_texture.c\
						p_east_texture.c\
						p_west_texture.c\
						p_sprite_texture.c\
						p_colors.c\
						p_map.c
						
GNL					=	get_next_line.c\
						get_next_line_utils.c\

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

VGNL				=	srcs/get_next_line
libraries	:	
				mkdir -p $(VLIBRARIES)
				$(MAKE) -C $(VLIBFT)
				$(MAKE) -C $(VMINILIBX)
				mv $(VMINILIBX)/$(MINILIBXDYLIB) $(DIR_LIBRARIES)/
				mv $(VLIBFT)/$(LIBFT) $(DIR_LIBRARIES)/



clean		:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(VLIBFT)
				$(MAKE) clean -C $(VMINILIBX)

fclean		:	clean
#				$(RM) $(NAME)
#				$(RM) $(LIBFT)
				$(RM) $(VMINILIBX)/$(MINILIBXDYLIB)
				$(RM) $(VMINILIBX)/*.o
				$(RM) $(VMINILIBX)/*.swiftmodule
				$(RM) $(VMINILIBX)/*.swiftdoc
				$(RM) $(DIR_LIBRARIES)

re			: 	fclean all

.PHONY: all clean fclean re libraries
# sert a definir ces mots comme des regles
