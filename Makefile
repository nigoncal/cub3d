.PHONY: all clean fclean re

# Names of files
NAME		=	cub3d.a
MLX			=	libmlx.dylib
PGM			=	cub3D
LIBFT		=	libft.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_MLX	=	mlx
PATH_LIBFT	=	libft

# List of sources
SRCS		=	$(addprefix $(PATH_SRC)/, main.c minimap.c raycasting.c keys.c get_map.c)
OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	cub3D.h

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra -g3
COMP_ADD	=	-I$(PATH_INC)

# Others Command
RM			=	rm

# Color Code and template code
_YELLOW		=	\033[33;1m
_GREEN		=	\033[32;1m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Wildcard rule

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c
	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

# Rules
all:
	$(MAKE) init
	$(MAKE) $(NAME)
	@echo "$(_SUCCESS) Compilation done"

init:	$(MLX)
	$(shell mkdir -p $(PATH_OBJ))

$(LIBFT) :
	$(MAKE) -C ./$(PATH_LIBFT)
	cp libft/libft.a ./$(LIBFT)

$(MLX): $(LIBFT)
	$(MAKE) -C ./$(PATH_MLX)
	cp ./$(PATH_MLX)/$(MLX) .

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(COMP) $(COMP_FLAG) $(NAME) $(LIBFT) $(MLX) ./$(PATH_SRC)/main.c -o $(PGM)

clean:
	$(RM) -rf $(PATH_OBJ)

fclean: clean
	$(MAKE) clean -C ./$(PATH_MLX)
	$(MAKE) fclean -C ./$(PATH_LIBFT)
	$(RM) -rf $(PGM)
	$(RM) -rf $(NAME)
	$(RM) -rf $(MLX)
	$(RM) -rf $(LIBFT)
	$(RM) -rf ./$(PATH_MLX)/$(MLX)
	$(RM) -rf ./$(PATH_MLX)/*.o
	$(RM) -rf ./$(PATH_MLX)/*.swiftmodule
	$(RM) -rf ./$(PATH_MLX)/*.swiftdoc

re: 
	$(MAKE) fclean
	$(MAKE) all
