# Variables pour les chemins
LIBFT_DIR = includes/Libft
LIBMLX_DIR = includes/mlx
GNL_DIR = includes/get_next_line
PRINTF_DIR = includes/ft_printf

# Les fichiers objets
SRCS = src/make_map.o src/flood_fill.o src/check_map.o src/so_long.o src/hook.o src/avatar_move.o src/free_data.o
OBJS = $(SRCS)

# Les bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx.a
GNL = $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Flags de compilation
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE
LDFLAGS = -L$(LIBMLX_DIR) -lmlx -lX11 -lXext -Lmlx -L/usr/lib -Imlx -lm -lz

# Nom de l'exécutable
NAME = so_long

# Règle par défaut : compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT) $(LIBMLX) $(GNL) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBMLX) $(GNL) $(PRINTF) $(LDFLAGS) -pie

# Règles pour les fichiers objets
src/%.o: src/%.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

# Règles pour libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Règles pour libmlx
$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

# Règles pour get_next_line
$(GNL):
	$(MAKE) -C $(GNL_DIR)

# Règles pour ft_printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Nettoyage des fichiers objets et des exécutables
fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	# $(MAKE) -C $(LIBMLX_DIR) fclean
	# $(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME) $(OBJS)

# Nettoyage complet : tout supprimer
clean: fclean
	rm -f $(OBJS)

# Recompiler tout
re: fclean $(NAME)
