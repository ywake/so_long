NAME	:= so_long
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft -I./minilibx-linux
CFLAGS	:= -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libs/libft.a
LIBS	:= -L./libs -lft -lXext -lX11 -lm
SRCDIR	:= ./srcs/
SRCS	:= main.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)

ifeq ($(shell uname), Linux)
	LIBS += -lmlx_Linux
else
	LIBS +=  -L/usr/X11R6/lib -lmlx_Darwin
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: $(SRCDIR)%.c
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

bonus: all

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

test:
	@echo $(LIBS)