CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes
RM = rm -rf
NAME = kuninotopb

SRCS = srcs/Contact.cpp
	   main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o kuninotopb

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean fclean re run

#.SILENT: