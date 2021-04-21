NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MINILIBX			=	libmlx.dylib

LIBRARIES			=	$(LIBCUB3D) $(LIBFT) $(MINILIBX)

SRCS_PATH			=	/srcs/
PARS_SRCS_PATH		=	/srcs/parsing/
LIBFT_PATH			=	/srcs/libft/
MINILIBX_PATH		=	/srcs/minilibx/

SRCS				=	start.c\
						tools.c\
						error_manager.c
	
PARS_SRCS			=	parser.c\
						p_resolution.c\
						p_textures.c\
						p_north_texture.c\
						p_south_texture.c\
						p_east_texture.c\
						p_west_texture.c\
						p_sprite_texture.c\
						p_colors.c\
						p_map.c



OBJS			=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))\
					$(addprefix $(PARS_SRCS_PATH), $(PARS_SRCS:.c=.o))

CUB3D_HEADER	=	header_cub3d.h

COMP_FLAGS		=	-Wall -Werror -Wextra 
COMP_ADD		=	-I$(HEADER)

RM				=	rm -rf

# Wildcard rule

$(PATH_OBJS)/%.o : $(PATH_SRCS)/%.c
	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

all:			$(NAME)
				$(MAKE) init
				$(MAKE) $(NAME)

%.o:			%.c $() $()
				gcc -I $(HEADER) $(LIBRARIES)

init:	$(MINILIBX)
	$(shell mkdir -p $(PATH_OBJS))

$(LIBCUB3D) :	$(OBJS)
				ar rcs $(LIBCUB3D) $(OBJS) $(CUB3D_HEADER)

$(LIBFT) :
	$(MAKE) -C ./$(PATH_LIBFT)
	cp libft/libft.a ./$(LIBFT)

$(MINILIBX): $(LIBFT)
	$(MAKE) -C ./$(PATH_MINILIBX)
	cp ./$(PATH_MINILIBX)/$(MINILIBX) .

$(NAME):		$(LIBCUB3D)
				make -C $(LIBFT_PATH)
				make -C $(MINILIBX_PATH)
				gcc $(FLAGS) $(LIBRARIES) main.c -o $(NAME)

clean:
	$(RM) -rf $(PATH_OBJS)

fclean: clean
	$(MAKE) clean -C ./$(PATH_MINILIBX)
	$(MAKE) fclean -C ./$(PATH_LIBFT)
	$(RM) -rf $(EXE)
	$(RM) -rf $(NAME)
	$(RM) -rf $(MINILIBX)
	$(RM) -rf $(LIBFT)
	$(RM) -rf ./$(PATH_MINILIBX)/$(MINILIBX)
	$(RM) -rf ./$(PATH_MINILIBX)/*.o
	$(RM) -rf ./$(PATH_MINILIBX)/*.swiftmodule
	$(RM) -rf ./$(PATH_MINILIBX)/*.swiftdoc

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
