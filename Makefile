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
						srcs/error_manager.c\
						srcs/start.c\
						srcs/parsing/parse_id.c\
						srcs/parsing/p_textures.c\
						srcs/parsing/p_north_texture.c\
						srcs/parsing/p_south_texture.c\
						srcs/parsing/p_east_texture.c\
						srcs/parsing/p_west_texture.c\
						srcs/parsing/p_floor.c\
						srcs/parsing/p_ceiling.c\
						srcs/parsing/p_map.c\
						srcs/parsing/store_map.c\
						srcs/parsing/square_map.c\
						srcs/parsing/check_map.c\
						srcs/parsing/flood_fill.c\
						srcs/parsing/find_player.c\
						srcs/graphic/temp.c

OBJS				=	$(SRCS:.c=.o)

H_CUB3D				=	srcs/header_cub3d.h

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
