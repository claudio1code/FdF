# Nome do executável
NAME = fdf

# Compilador e flags de compilação
CC = cc
CFLAGS = -Wall -Werror -Wextra

# --- Diretórios ---
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = includes/
LIBFT_DIR = libft/
MLX_DIR = minilibx-linux/

# --- Ficheiros ---
SRCS_LIST = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))

# --- Bibliotecas ---
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# --- Flags de Inclusão e Linkagem (como no so_long) ---
INCLUDES = -I $(INCS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# --- Cores ---
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
DEF_COLOR = \033[0;39m

# --- Regras ---

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@printf "$(YELLOW)A linkar $(NAME)... $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "$(GREEN)$(NAME) criado com sucesso!$(DEF_COLOR)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@printf "$(CYAN)A compilar $<... $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX_LIB):
	@make -sC $(MLX_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re