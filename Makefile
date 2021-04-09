.PHONY: all clean fclean re

# Names of files
NAME		=	miniRT.a
MLX			=	libmlx.dylib
PGM			=	miniRT
LIBFT		=	libft.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	obj
PATH_MLX	=	minilibx
PATH_LIBFT	=	libft

# List of sources
SRCS		=	$(addprefix $(PATH_SRC)/, main.c)
OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(addprefix $(PATH_INC)/, header.h)

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

# Functions
all:	init $(NAME)
	@echo "$(_SUCCESS) Compilation done"

init:	$(MLX)
	$(shell mkdir -p $(PATH_OBJ))

$(LIBFT) :
	$(MAKE) -C ./$(PATH_LIBFT)
	cp libft/libft.a ./$(LIBFT)

$(MLX): $(LIBFT)
	$(MAKE) -C ./$(PATH_MLX)
	cp ./$(PATH_MLX)/$(MLX) .

$(NAME): $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS)
	$(COMP) $(COMP_FLAG) $(NAME) $(LIBFT) $(MLX) ./$(PATH_SRC)/main.c -o $(PGM)

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c $(INCS)
	$(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@

clean:
	$(RM) -rf $(PATH_OBJ)

fclean: clean
	$(MAKE) clean -C ./$(PATH_MLX)
	$(MAKE) fclean -C ./$(PATH_LIBFT)
	$(RM) -rf $(PGM)
	$(RM) -rf $(NAME)
	$(RM) -rf $(MLX)
	$(RM) -rf ./$(PATH_MLX)/$(MLX)
	$(RM) -rf ./$(PATH_MLX)/*.o
	$(RM) -rf ./$(PATH_MLX)/*.swiftmodule
	$(RM) -rf ./$(PATH_MLX)/*.swiftdoc

re: fclean all