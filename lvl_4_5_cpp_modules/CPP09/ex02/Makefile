CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -O3 #-DLOGS
INCLUDE = -I./includes
VPATH = srcs
RM = rm -rf

GENERAL = PmergeMe

NAME = PmergeMe
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

run: all clean
	@echo ""
	@echo "TEST 1"
	./$(NAME) 3 5 9 7 4
	@echo ""
#	@echo "TEST 2"
#	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	@echo "TEST 4"
	./$(NAME) -1 2
	@echo ""

noleaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re run

#.SILENT: