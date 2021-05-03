# Si tu touch le header de la libft, ca ne remake pas, ca devrait

NAME				=	libcub3d.a
# celui-ci n'est pas liste dans les libraries car il est cree, a la rigueur
# deplaces le apres
EXE					=	cub3d
LIBFT				=	libft.a
MLXDL				=	libmlx.dylib


LIBRARIES			=	srcs/$(NAME) srcs/libft/$(LIBFT)\
						srcs/minilibx/$(MLXDL)

VPATH				=	srcs parsing libft minilibx textures libraries $(VSCRS)\
						$(VLIBFT) $(VMLX) $(VPARSING) $(VLIBFT) $(VTEXTURES)
# est-ce que libraries est a ajouter ici, vu que c'est un nouveau dir que tu
# crees dans ton Makefile. Je sais pas pourquoi je le sens mal. Testes et tu
# verras

VSRCS				=	srcs/
VLIBFT				=	srcs/libft/
VMLX				=	srcs/minilibx/
VPARSING			=	srcs/parsing/
VTEXTURES			=	srcs/textures/

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

OBJS				=	$(SRCS:.c=.o) $(PARSING:.c=.o)

HEADERS				=	srcs/header_cub3d.h srcs/libft/libft.h

H_CUB3D				=	srcs/header_cub3d.h

COMP				=	clang -Wall -Wextra -Werror

RM					=	rm -rf

#$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

%.o:				%.c $(HEADERS)
					$(COMP) -I $(HEADERS) $(LIBRARIES) -c $< -o $@


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

$(NAME)		:	$(H_CUB3D) $(OBJS) $(LIBFT) $(MLXDL)
				$(COMP) -I $(H_CUB3D) main.c -o $(NAME)

################################################################################
# attention a OpenGL qui normalement correspond a la minilibx non beta
################################################################################

$(EXE)		:	$(NAME)
				$(COMP) $(NAME) $(LIBRARIES) main.c -o $(EXE)

#$(LIBFT)	:
#				$(MAKE) -C $(VLIBFT)

#$(MLXDL)	:
#				$(MAKE) -C $(VMLX)

libraries	:	
				$(MAKE) -C $(VLIBFT)
				$(MAKE) -C $(VMLX)

#libraries	:	$(LIBFT) $(MLXDL)

clean		:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(VLIBFT)
				$(MAKE) clean -C $(VMLX)

fclean		:	clean
#				$(RM) $(NAME)
#				$(RM) $(LIBFT)
				$(RM) $(VMLX)/$(MLXDL)
				$(RM) $(VMLX)/*.o
				$(RM) $(VMLX)/*.swiftmodule
				$(RM) $(VMLX)/*.swiftdoc
				$(RM) $(VLIBRARIES)

re			: 	fclean all

.PHONY: all clean fclean re libraries
# sert a definir ces mots comme des regles
