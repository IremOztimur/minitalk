SRC = 	ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_itoa.c \
		ft_split.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCS = ${addprefix ./utils/lib/,${SRC}} \
		utils/ft_printf/ft_printf.c

OBJS = ${SRCS:.c=.o}
NAME = utils.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
AR = ar -rcs


all: ${NAME} server client

server: ${NAME} server.c
	@${CC} ${CFLAGS} -o server server.c ${NAME}

client: ${NAME} client.c
	@${CC} ${CFLAGS} -o client client.c ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo "Succesfully archieved"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

run: ${NAME}
	@${CC} ${CFLAGS} ${MAIN} ${NAME}
	@${OUT}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME} server client

re: fclean all

.PHONY: fclean clean all re .c.o
