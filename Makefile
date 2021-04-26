NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MINILIBX			=	libmlx.dylib

LIBRARIES			=	$(addprefix $(PATH_SRCS), $(LIBCUB3D))\
						$(addprefix $(PATH_LIBFT), $(LIBFT))\
						$(addprefix $(PATH_MINILIBX), $(MINILIBX))

PATH_LIBFT			=	srcs/libft/
PATH_MINILIBX		=	srcs/minilibx/

SRCS				=	start.c\
						tools.c\
						error_manager.c\
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

HEADERS				=	$(PATH_SRCS)header_cub3d.h\
						$(PATH_LIBFT)header_libft.h\
						$(PATH_MINILIBX)

INC_HEADERS			=	$(addprefix -I, $(HEADERS))

OBJS				=	$(addprefix $(SRCS:.c=.o))\

CUB3D_HEADER		=	header_cub3d.h

COMP				=	clang

CFLAGS				=	-Wall -Wextra -Werror

#$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

%.o:				%.c $(HEADERS)
					$(COMP) $(CFLAGS) -I $(MINILIBX_PATH) -c $< -o $@
					$(COMP) $(CFLAGS) -I $(HEADERS) $(LIBRARIES) -c $< -o $@

################################################################################
# compiler cc au lieu de $(COMP)
# si tu touch un fichier de la libft, il ne faut pas avoir besoin de faire
# make re, pour l'instant ce serait le cas selon Nico
################################################################################

all:			
				$(MINILIBX)
				$(MAKE) $(NAME)

$(LIBCUB3D) :	$(PATH_SCRS) $(PATH_PARS_SRCS)
				ar rcs $(LIBCUB3D) $(PATH_SCRS) $(PATH_PARS_SRCS)\
					$(addprefix $(PATH_SRCS), $(CUB3D_HEADER))

$(MINILIBX) :	
				$(MAKE) -C $(PATH_MINILIBX)

$(NAME):		$(LIBCUB3D)
				$(MAKE) -C $(PATH_LIBFT)
#				$(MAKE) -C $(MINILIBX_PATH)
				$(COMP) $(CFLAGS) -framework OpenGL -framework AppKit\
					-L $(MINILIBX_PATH) -l $(MINILIBX_PATH) $(LIBRARIES)\
					-I $(MINILIBX_PATH) main.c -o $(NAME)
################################################################################
# attention a OpenGL qui normalement correspond a la minilibx non beta
################################################################################

clean:
				rm -rf $(OBJS)
				$(MAKE) clean -C $(LIBFT_PATH)
				$(MAKE) clean -C $(MINILIBX_PATH)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(LIBFT)
				rm -rf ./$(PATH_MINILIBX)/$(MINILIBX)
				rm -rf ./$(PATH_MINILIBX)/*.o
				rm -rf ./$(PATH_MINILIBX)/*.swiftmodule
				rm -rf ./$(PATH_MINILIBX)/*.swiftdoc

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
