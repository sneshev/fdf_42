NAME = fdf
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror

MINILIBX = https://github.com/42paris/minilibx-linux.git
MLIBX_PATH = minilibx
LIBFT = git@github.com:sneshev/libft_42.git
LIBFT_PATH = libft

all:  libft mlibx $(NAME)

mlibx: 
	@[ -d "$(MLIBX_PATH)" ] || (git clone $(MINILIBX) $(MLIBX_PATH) && cd $(MLIBX_PATH) && make)

libft:
	@[ -d "$(LIBFT_PATH)" ] || git clone $(LIBFT) $(LIBFT_PATH);
	@cd $(LIBFT_PATH) && make 

SRCS = $(shell find src -type f -name '*.c') 
OBJS_DIR = obj
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

LIBS = -L$(LIBFT_PATH) -lft -L$(MLIBX_PATH) -lmlx -lXext -lX11

# $(NAME): $(OBJS) libft mlibx   <- relinks
$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a $(MLIBX_PATH)/libmlx.a
	$(CC) $(OBJS) $(LIBS) -o $(NAME) -lm

clean:
	rm -rf $(OBJS_DIR) $(NAME)

fclean:
	rm -rf $(MLIBX_PATH) $(LIBFT_PATH) $(OBJS_DIR) $(NAME)

re: fclean all