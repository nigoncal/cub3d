NAME				=	libcub3d.a
EXE					=	cub3d
LIBFT				=	libft.a
MLXDL				=	libmlx.dylib

LIBS				=	libft.a\
						libmlx.dylib\
						libcub3d.a

VPATH				=	libft config textures srcs mlx parsing\
						parsing_textures colors map graphic engine\
						libraries $(VLIBFT) $(VSCRS) $(VMLX) $(VPARSING)\
						$(VPARSING_TEXTURES) $(VCOLORS) $(VMAP)

VLIBS				=	$(VLIBFT)libft.a\
						$(VMLX)libmlx.dylib

VLIBFT				=	libft/
VMLX				=	srcs/mlx/
VPARSING			=	srcs/parsing/
VPARSING_TEXTURES	=	srcs/parsing/parsing_textures/
VCOLORS				=	srcs/parsing/colors/
VMAP				=	srcs/parsing/map/

SRCS				=	srcs/parsing/error_manager.c\
						srcs/parsing/parse_id.c\
						srcs/parsing/parsing_textures/textures.c\
						srcs/parsing/parsing_textures/north_texture.c\
						srcs/parsing/parsing_textures/south_texture.c\
						srcs/parsing/parsing_textures/east_texture.c\
						srcs/parsing/parsing_textures/west_texture.c\
						srcs/parsing/colors/floor.c\
						srcs/parsing/colors/ceiling.c\
						srcs/parsing/map/parse_map.c\
						srcs/parsing/map/store_map.c\
						srcs/parsing/map/square_map.c\
						srcs/parsing/map/check_map.c\
						srcs/graphic/temp.c

OBJS				=	$(SRCS:%.c=%.o)

H_CUB3D				=	srcs/cub3d.h

COMP				=	clang -Wall -Wextra -Werror -g3

RM					=	rm -rf

%.o					:	%.c $(H_CUB3D)
						$(COMP) -I$(H_CUB3D) -c $< -o $@

all					:	libs $(NAME) $(EXE)	

libs				:	
						$(MAKE) -C $(VLIBFT)
						ln -sf $(VLIBFT)$(LIBFT) .
						$(MAKE) -C $(VMLX)
						ln -sf $(VMLX)$(MLXDL) .

$(NAME)				:	$(OBJS)
						ar rcs $(NAME) $(OBJS)

$(EXE)				:	$(OBJS) $(LIBS)
						$(COMP) $(LIBS) srcs/main.c -o $(EXE)

clean				:
						$(RM) $(OBJS)
						$(MAKE) clean -C $(VLIBFT)
						$(MAKE) clean -C $(VMLX)

fclean				:	
						$(RM) $(OBJS) $(LIBS) $(EXE)
						$(MAKE) fclean -C $(VLIBFT)
						$(MAKE) clean -C $(VMLX)

re					: 	fclean all

.PHONY: all libs clean fclean re libraries
