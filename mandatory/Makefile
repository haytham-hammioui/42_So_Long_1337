# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 16:40:14 by hhammiou          #+#    #+#              #
#    Updated: 2025/01/22 20:18:05 by hhammiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

BLUE = "\033[0;34m"
PURPLE = "\033[1;35m"
YELLOW = "\033[0;33m"
LIGHT_YELLOW = "\033[1;33m"
NOCOLOR = "\033[0;37m"

SRCS	=	../GNL/get_next_line.c				\
			../GNL/get_next_line_utils.c		\
			../FT_PRINTF/ft_printf.c			\
			../FT_PRINTF/ft_putchar.c			\
			../FT_PRINTF/ft_putnbr.c			\
			../FT_PRINTF/ft_putstr.c			\
			utils/ft_check_file.c				\
			utils/ft_check_path.c				\
			utils/ft_errors.c					\
			utils/ft_exit.c						\
			utils/ft_get_map.c					\
			utils/ft_key_hook.c					\
			utils/ft_map_elements.c				\
			utils/ft_map_validation.c			\
			utils/ft_movement.c					\
			utils/ft_put_map_image.c			\
			utils/ft_split.c					\
			utils/ft_helpers.c					\
			so_long.c							\
			
all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo $(BLUE)"Compiling so_long..."$(NOCOLOR)
		@echo $(PURPLE)"███████╗ ██████╗           ██╗      ██████╗ ███╗   ██╗ ██████╗ "$(NOCOLOR)
		@echo $(PURPLE)"██╔════╝██╔═══██╗          ██║     ██╔═══██╗████╗  ██║██╔════╝ "$(NOCOLOR)
		@echo $(PURPLE)"███████╗██║   ██║          ██║     ██║   ██║██╔██╗ ██║██║  ███╗"$(NOCOLOR)
		@echo $(PURPLE)"╚════██║██║   ██║          ██║     ██║   ██║██║╚██╗██║██║   ██║"$(NOCOLOR)
		@echo $(PURPLE)"███████║╚██████╔╝ ███████╗ ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"$(NOCOLOR)
		@echo $(PURPLE)"╚══════╝ ╚═════╝  ╚══════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "$(NOCOLOR)
		@echo $(BLUE)"                                      By: hhammiou42 [ESBG 💜]"$(NOCOLOR)
		@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@
		@echo $(BLUE)"Compilation finished !!"$(NOCOLOR)
		@echo $(YELLOW)"type "$(LIGHT_YELLOW)"\`./so_long maps/{choose_a_map}\`"$(YELLOW)" to start the game!"$(NOCOLOR)

%.o:%.c so_long.h ../GNL/get_next_line.h ../FT_PRINTF/ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo $(BLUE)"Object files removed"$(NOCOLOR)

fclean: clean
	@rm -f $(NAME)
	@echo $(YELLOW)"$(NAME) removed"$(NOCOLOR)

re: fclean all

.PHONY: clean