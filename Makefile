NAME				=	libcub3d.a
EXE					=	cub3d
#celui-ci n'est pas liste dans les libraries car il est cree, a la rigueur desplaces le apres
LIBFT				=	libft.a
MINILIBXDYLIB		=	libmlx.dylib


LIBRARIES			=	srcs/$(LIBCUB3D) srcs/libft/$(LIBFT)\
						srcs/minilibx$(MINILIBXDYLIB))

VPATH				=	srcs parsing get_next_line libft minilibx textures\
						libraries $(VSCRS) $(VLIBFT) $(VMINILIBX) $(VPARSING)\
						$(VGNL) $(VLIBRARIES) $(VLIBFT) $(VTEXTURES)
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

# tu vas certainement rajouter des fichiers pour toute la partie graphique
						
GNL					=	get_next_line.c\
						get_next_line_utils.c\

OBJS				=	$(SRCS:.c=.o) $(PARSING:.c=.o)

HEADERS				=	srcs/header_cub3d.h srcs/get_next_line/get_next_line.h\
						srcs/minilibx/mlx.h

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

all:			libraries $(NAME) $(EXE)	

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
# attention a la cariabl LIBCUB3D qui est devenur NAME, regardes par rapport
# au Makefile de guhernan et cherches partout dans ton code ou il y a LIBCUB3D
# et qu'est-ce que ca fait a chaque fois.


$(NAME)		:	$(OBJS) $(LIBFT)
# ICI
#				$(MAKE) -C $(VMINILIBX)
				$(COMP) $(CFLAGS) -framework OpenGL -framework AppKit\
					-L $(VMINILIBX) -l $(VMINILIBX) $(LIBRARIES)\
					-I $(VMINILIBX) main.c -o $(NAME)
################################################################################
# attention a OpenGL qui normalement correspond a la minilibx non beta
################################################################################

$(EXE)		:	$(NAME)

libraries	:	
				mkdir -p $(VLIBRARIES)
				$(MAKE) -C $(VLIBFT)
				mv $(VLIBFT)/$(LIBFT) $(VLIBRARIES)/
				$(MAKE) -C $(VMINILIBX)
				mv $(VMINILIBX)/$(MINILIBXDYLIB) $(VLIBRARIES)/



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
				$(RM) $(VLIBRARIES)

re			: 	fclean all

.PHONY: all clean fclean re libraries
# sert a definir ces mots comme des regles
