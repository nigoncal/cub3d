NAME				=	libcub3d.a
EXE					=	cub3d
LIBFT				=	libft.a
MLXDL				=	libmlx.dylib

LIBS				=	libft.a\
						libmlx.dylib\
						libcub3d.a

VPATH				=	srcs parsing libft mlx textures libraries $(VSCRS)\
						$(VLIBFT) $(VMLX) $(VPARSING) $(VTEXTURES)

VLIBS				=	$(VLIBFT)libft.a\
						$(VMLX)libmlx.dylib

VLIBFT				=	libft/
VMLX				=	srcs/mlx/
VTEXTURES			=	srcs/textures/

SRCS				=	srcs/main.c\
						srcs/start.c\
						srcs/parsing/error_manager.c\
						srcs/parsing/parse_id.c\
						srcs/parsing/textures/textures.c\
						srcs/parsing/textures/north_texture.c\
						srcs/parsing/textures/south_texture.c\
						srcs/parsing/textures/east_texture.c\
						srcs/parsing/textures/west_texture.c\
						srcs/parsing/textures/store_textures.c\
						srcs/parsing/colors/floor.c\
						srcs/parsing/colors/ceiling.c\
						srcs/parsing/map/parse_map.c\
						srcs/parsing/map/store_map.c\
						srcs/parsing/map/square_map.c\
						srcs/parsing/map/check_map.c\
						srcs/parsing/map/find_player.c\
						srcs/parsing/map/flood_fill.c

OBJS				=	$(SRCS:.c=.o)

H_CUB3D				=	srcs/cub3d.h

COMP				=	clang -Wall -Wextra -Werror -g3

RM					=	rm -rf

%.o			:	%.c $(H_CUB3D)
				$(COMP) -I$(H_CUB3D) -c $< -o $@

all			:	libs $(NAME) $(EXE)	

libs		:	
				$(MAKE) -C $(VLIBFT)
				ln -sf $(VLIBFT)$(LIBFT) .
				$(MAKE) -C $(VMLX)
				ln -sf $(VMLX)$(MLXDL) .

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(EXE)		:	$(OBJS) $(LIBS)
				$(COMP) $(LIBS) -o $(EXE)

clean		:
				$(RM) $(OBJS)
				$(MAKE) clean -C $(VLIBFT)
				$(MAKE) clean -C $(VMLX)

fclean		:	
				$(RM) $(OBJS) $(LIBS) $(EXE)
				$(MAKE) fclean -C $(VLIBFT)
				$(MAKE) clean -C $(VMLX)

re			: 	fclean all

.PHONY: all libs clean fclean re libraries
