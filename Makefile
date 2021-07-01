NAME	:= so_long
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft -I./minilibx-linux
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libs/libft.a
LIBS	:= -L./libs -lft -lXext -lX11 -lm
SRCDIR	:= ./srcs/
SRCS	:= main.c error.c callbacks.c\
			game/game.c game/console.c game/img.c game/draw.c\
			stage/stage.c stage/valid_map.c\
			assets/texture.c\
			utils/ft_xmalloc.c utils/get_next_line.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)
B_SRCS	:= main.c error.c callbacks_bonus.c\
			game/game.c game/console.c game/img.c game/draw_bonus.c\
			stage/stage.c stage/valid_map_bonus.c\
			assets/texture_bonus.c\
			utils/ft_xmalloc.c utils/get_next_line.c
B_OBJS	:= $(B_SRCS:%.c=$(SRCDIR)%.o)
BONUSFLG:= .bonus_flg

ifeq ($(shell uname), Linux)
	LIBS += -lmlx_Linux
else
	LIBS +=  -L/usr/X11R6/lib -lmlx_Darwin
endif

.PHONY: all clean fclean re bonus test

all: $(NAME)

%.o: $(SRCDIR)%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

init:
	git submodule update --init
	$(MAKE) -C ./minilibx-linux
	mv ./minilibx-linux/libmlx*.a ./libs/

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft
	mv ./Libft/libft.a ./libs/libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(BONUSFLG)

$(BONUSFLG): $(B_OBJS) $(LIBFT)
	@touch $(BONUSFLG)
	$(CC) $(B_OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	rm -f libs/libft.a
	rm -f $(NAME)

re: fclean all

norm:
	@norminette srcs includes Libft | grep -v ": OK!" \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"

test: $(OBJS) $(LIBFT)
	$(CC) $(LIBS) $(OBJS) ./test/sharedlib.c -o $(NAME)

autotest: test
	bash auto_test.sh $(TEST)
