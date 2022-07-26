# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 17:57:12 by smessal           #+#    #+#              #
#    Updated: 2022/07/26 18:01:26 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	push_swap.c utils.c utils2.c utils3.c movements.c \
						movements2.c movements3.c errors.c free.c \

OBJ					=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Wextra -Werror

NAME				=	push_swap

all:				$(NAME)

$(NAME):	$(OBJS) #ft_printf.
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) -o $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus