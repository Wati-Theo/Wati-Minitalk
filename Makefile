SERVER= server
CLIENT= client

ServerFILES=	Wati-Server.c	\
				Wati-Utilis.c

ClientFILES=	Wati-Client.c	\
				Wati-Utilis.c

HEADFILES= Wati_Minitalk.h

ServerF= 	${ServerFILES}

ClientF=	${ClientFILES}

ServerO= ${ServerF:.c=.o}

ClientO= ${ClientF:.c=.o}

CC= gcc

all: ${SERVER} ${CLIENT}

%.o:	%.c ${HEADFILES}
		${CC} -Wall -Wextra -Werror -Imlx -c $< -o $@

${SERVER}:	${ServerO}
	${CC} -Wall -Wextra -Werror ${LIBRARY} $^ -o ${SERVER}

${CLIENT}:	${ClientO}
	${CC} -Wall -Wextra -Werror ${LIBRARY} $^ -o ${CLIENT}

clean: 
	${RM} ${ServerO} ${ClientO}

fclean: clean
	${RM} ${SERVER} ${CLIENT}

re: fclean all

.PHONY: all clean fclean re