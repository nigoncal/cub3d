NAME				=	cub3d
LIBCUB3D			=	libcub3d.a
LIBFT				=	libft.a
MINILIBX			=	libmlx.dylib

VPATH				=	srcs\
						srcs/parsing\
						srcs/libft\
						srcs/minilibx\
						srcs/get_next_line\

LIBRARIES			=	$(addprefix $(SRCS_PATH), $(LIBCUB3D))\
						$(addprefix $(LIBFT_PATH), $(LIBFT))\
						$(addprefix $(MINILIBX_PATH), $(MINILIBX))

SRCS_PATH			=	srcs/
PARS_SRCS_PATH		=	srcs/parsing/
LIBFT_PATH			=	srcs/libft/
MINILIBX_PATH		=	srcs/minilibx/
OBJS_PATH			=	objs/

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

HEADERS				=	$(SRCS_PATH)header_cub3d.h\
						$(LIBFT_PATH)header_libft.h\
						$(MINILIBX_PATH)

INC_HEADERS			=	$(addprefix -I, $(HEADERS))

OBJS				=	$(addprefix $(SRCS_PATH), $(SRCS:.c=.o))\
						$(addprefix $(PARS_SRCS_PATH), $(PARS_SRCS:.c=.o))

CUB3D_HEADER		=	header_cub3d.h

CFLAGS				=	-Wall -Wextra -Werror

#$(OBJS_PATH)/%.o : $(PATH_SRCS)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

$(OBJS_PATH)/%.o:	$(SRCS_PATH)%.c $(HEADERS)
					gcc $(CFLAGS) -I $(MINILIBX_PATH) -c $< -o $@
					gcc $(CFLAGS) -I $(HEADERS) $(LIBRARIES) -c $< -o $@

all:			
				$(MAKE) init
				$(MAKE) $(NAME)

init:			$(MINILIBX)
				$(shell mkdir -p $(OBJS_PATH))

$(LIBCUB3D) :	$(OBJS)
				ar rcs $(LIBCUB3D) $(OBJS)\
					$(addprefix $(SRCS_PATH), $(CUB3D_HEADER))

$(MINILIBX) :	
				$(MAKE) -C $(MINILIBX_PATH)

$(NAME):		$(LIBCUB3D)
				$(MAKE) -C $(LIBFT_PATH)
#				$(MAKE) -C $(MINILIBX_PATH)
				gcc $(CFLAGS) -framework OpenGL -framework AppKit\
					-L $(MINILIBX_PATH) -l $(MINILIBX_PATH) $(LIBRARIES)\
					-I $(MINILIBX_PATH) main.c -o $(NAME)

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
