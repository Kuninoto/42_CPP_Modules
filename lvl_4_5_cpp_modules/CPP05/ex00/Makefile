CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O3 -Wshadow -Wno-shadow -fsanitize=address
INCLUDE = -I./includes
VPATH = srcs
RM = rm -rf

GENERAL = Bureaucrat

NAME = ex00
SRCS = $(addsuffix .cpp, $(GENERAL))\
	   main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re clean
	echo ""
	./$(NAME)

leaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re run

#.SILENT: