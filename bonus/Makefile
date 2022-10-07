SRC_OPERATIONS	=	./operations/operation.c	\
					./operations/run_operation.c

SRC_PRESETTINGS	=	./pre_settings/check_args.c	\
					./pre_settings/initial.c	\

SRC_GNL			=	./get_next_line/get_next_line.c	\
					./get_next_line/get_next_line_utils.c

SRC_RESET		=	./reset_data.c

SRC_MAIN		=	./checker.c	\
					./main.c

OBJS_OPERATIONS		=	${SRC_OPERATIONS:.c=.o}
OBJS_PRESETTINGS	=	${SRC_PRESETTINGS:.c=.o}
OBJS_GNL			=	${SRC_GNL:.c=.o}
OBJS_RESET			=	${SRC_RESET:.c=.o}
OBJS_MAIN			=	${SRC_MAIN:.c=.o}

LIBFT				=	libft.a
LIBFT_DIR			=	../libft

CFLAGS				=	-Wall -Wextra -Werror

NAME				=	checker

CC					=	gcc

#CFLAGS				=	-g3 -fsanitize=address

RM					=	rm -rf

all:	$(NAME)

.c.o:	${CC} ${CFLAGS} -Idir -c  $< -o ${<:.c=.o}

$(NAME): $(OBJS_OPERATIONS) $(OBJS_PRESETTINGS) $(OBJS_GNL) $(OBJS_RESET) $(OBJS_MAIN)
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) -Idir -o $@ $^ -L$(LIBFT_DIR) -lft

clean:
		$(RM) $(OBJS_OPERATIONS) $(OBJSPRESETTINGS) $(OBJS_GNL) $(OBJS_RESET) $(OBJS_MAIN)
		make -C $(LIBFT_DIR) $@

fclean:	clean
		${RM} ${NAME}
		make -C $(LIBFT_DIR) $@

re:		fclean all

.PHONY:	all clean fclean re