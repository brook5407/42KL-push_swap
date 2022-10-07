SRC_OPERATIONS		=	./operations/push.c			\
						./operations/reverse_rotate.c\
						./operations/rotate.c		\
						./operations/swap.c			\

SRC_PRE_SETTINGS	=	./pre_settings/check_args.c	\
						./pre_settings/initial.c	\

SRC_UTILS			=	./utils/reset_data.c		\
						./utils/utils.c				\

SRC_MAIN			=	./main.c

SRC_SORT			=	./sort/sort_small_stack.c	\
						./sort/sort_big_stack.c

OBJS_OPERATIONS		=	${SRC_OPERATIONS:.c=.o}
OBJS_PRE_SETTINGS	=	${SRC_PRE_SETTINGS:.c=.o}
OBJS_UTILS			=	${SRC_UTILS:.c=.o}
OBJS_MAIN			=	${SRC_MAIN:.c=.o}
OBJS_SORT			=	${SRC_SORT:.c=.o}

LIBFT				=	libft.a
LIBFT_DIR			=	./libft

BONUS_DIR			=	./bonus

CFLAGS				=	-Wall -Wextra -Werror

NAME				=	push_swap

CC					=	gcc

#CFLAGS				=	-g3 -fsanitize=address

RM					=	rm -rf

all:	$(NAME)

.c.o:	${CC} ${CFLAGS} -Idir -c  $< -o ${<:.c=.o}

bonus:	re
		make -C $(BONUS_DIR)
		cp ./bonus/checker ./checker

$(NAME): $(OBJS_OPERATIONS) $(OBJS_PRE_SETTINGS) $(OBJS_UTILS) $(OBJS_MAIN) $(OBJS_SORT)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) -Idir -o $@ $^ -L$(LIBFT_DIR) -lft

clean:
		$(RM) ${OBJS_OPERATIONS} ${OBJS_PRE_SETTINGS} ${OBJS_UTILS} ${OBJS_MAIN} $(OBJS_SORT)
		make -C $(LIBFT_DIR) $@
		make -C $(BONUS_DIR) $@

fclean:	clean
		${RM} ${NAME} checker
		make -C $(LIBFT_DIR) $@
		make -C $(BONUS_DIR) $@

re:		fclean all

.PHONY:	all clean fclean re
