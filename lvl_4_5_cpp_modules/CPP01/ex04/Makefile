CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = rm -rf

NAME = wannabe_sed
SRCS = main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.replace

re: fclean all

run: all clean
	./$(NAME) test.txt "replace" "abc"

.PHONY: all clean fclean re run

#.SILENT: