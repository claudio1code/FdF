CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = fdf

SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = includes/
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/

SRCS = main.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libml.a

INCLUDES = -I $(INCS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

LDFLAGS = -L$(LIBFT_DIR) -lft - L$(MLKDIR) -lmlx -lXext

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT) $(MLX_LIB)
	@echo "$(YELLOW)Linking $(NAME)... $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(DEF_COLOR)\n"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) 