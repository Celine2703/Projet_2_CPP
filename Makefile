SRCS = main.cpp Bank.cpp

HEAD = Bank.hpp

OBJS = $(SRCS:.cpp=.o)

NAME = bank

CC = c++ -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re