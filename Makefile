# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smessal <smessal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 17:57:12 by smessal           #+#    #+#              #
#    Updated: 2022/07/27 17:34:55 by smessal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=	push_swap.c utils.c utils2.c utils3.c movements.c \
						movements2.c movements3.c errors.c free.c \
						algos.c algos2.c \

OBJ					=	$(SRCS:.c=.o)

CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Wextra -Werror

NAME				=	push_swap.a

PROG				=	push_swap


all:				$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJ)
			$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(NAME)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(OBJ) $(PROG) $(NAME)

re:					fclean $(NAME)

.PHONY:				all clean fclean re bonus