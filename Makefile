NAME	:= so_long
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft -I./minilibx-linux
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libs/libft.a
LIBS	:= -L./libs -lft -lmlx_$(shell uname) -lXext -lX11 -lm
SRCDIR	:= ./srcs/
SRCS	:= main.c error.c callbacks.c\
			game/game.c game/console.c game/img.c game/draw.c\
			stage/stage.c stage/valid_map.c\
			assets/texture.c\
			utils/ft_xmalloc.c utils/get_next_line.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)
B_SRCS	:= main.c error.c callbacks_bonus.c\
			game/game_bonus.c game/console.c game/img.c game/draw_bonus.c game/player_bonus.c\
			stage/stage.c stage/valid_map_bonus.c\
			assets/texture_bonus.c\
			utils/ft_xmalloc.c utils/get_next_line.c
B_OBJS	:= $(B_SRCS:%.c=$(SRCDIR)%.o)
BONUSFLG:= .bonus_flg
DSTRCTR	:= ./test/destructor.c

# ifeq ($(shell uname), Linux)
# 	LIBS += -lmlx_Linux -lXext -lX11 -lm
# else
# 	LIBS += -L/usr/X11R6/lib -lmlx_Darwin -lXext -lX11 -lm
# endif

ifeq ($(shell uname), Darwin)
	LIBS += -L/usr/X11R6/lib
endif

.PHONY: all clean fclean re bonus test init norm autotest

all: $(NAME)

%.o: $(SRCDIR)%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

init:
	git submodule update --init
	$(MAKE) -C ./minilibx-linux
	cp ./minilibx-linux/libmlx*.a ./libs/

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft
	cp ./Libft/libft.a ./libs/libft.a

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(BONUSFLG)

$(BONUSFLG): $(LIBFT) $(B_OBJS)
	@touch $(BONUSFLG)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f leaksout
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f libs/libft.a
	rm -f $(NAME)
	rm -f .bonus_flg

re: fclean all

norm:
	@norminette srcs includes Libft | grep -v -e ": OK!" -v -e "Missing or invalid header. Header are being reintroduced as a mandatory part of your files. This is not yet an error." \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"


$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

leak_Darwin: $(LIBFT) $(OBJS) $(DSTRCTR)
	$(CC) $(CFLAGS) $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

leak_Linux: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

leak: leak_$(shell uname)

bonus_leak_Darwin: $(LIBFT) $(B_OBJS) $(DSTRCTR)
	$(CC) $(CFLAGS) $(B_OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

bonus_leak_Linux: $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -fsanitize=address -o $(NAME) $(LIBS)

bonus_leak: bonus_leak_$(shell uname)

autotest: leak
	bash auto_test.sh $(TEST)
