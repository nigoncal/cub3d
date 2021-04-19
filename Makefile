.PHONY: all clean fclean re

# Names of files
NAME		=	cub3d.a
MLX			=	libmlx.dylib
PGM			=	cub3D
LIBFT		=	libft.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	obj
PATH_MLX	=	minilibx
PATH_LIBFT	=	libft

# List of sources
SRCS		=	$(addprefix $(PATH_SRC)/, parsing.c parsing_utils.c parsing_textures.c main.c\
parsing_skip.c parsing_map.c get_next_line.c get_next_line_utils.c\
exit.c)
#celle qui marche mais met les .o dans /srcs :
OBJS		=	${SRCS:.c=.o}
#celle de base :
#OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
#OBJS		=	${SRCS:%.c=$(PATH_OBJ)/%.o}
#OBJS		=	${SRCS:.c=.o}
INCS		=	cub3D.h

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra 
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
#rule d'origine :
#$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

#$(OBJS) : $(SRCS)
#	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

$(PATH_OBJ)/%.o : %.c $(PATH_INC)/cub3D.h
	mkdir -p $(PATH_OBJ)
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

$(NAME): ${OBJS}
	ar rcs $(NAME) ${OBJS}
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
