CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address #-DLOGS
INCLUDE = -I./includes
VPATH = srcs
RM = rm -rf

GENERAL = 

NAME = iter
SRCS = main.cpp

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
	./$(NAME) 0
	@echo ""
	@echo "TEST 2"
	./$(NAME) nan
	@echo ""
	@echo "TEST 3"
	./$(NAME) 42.0f

noleaks: re clean
	echo ""
	valgrind --leak-check=full -s ./$(NAME)

.PHONY: all clean fclean re run

#.SILENT: