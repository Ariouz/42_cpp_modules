NAME= accounts

SRCS= tests.cpp Account.cpp
OBJS= $(SRCS:.cpp=.o)

FLAGS= -std=c++98 -Wall -Werror -Wextra

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all re clean fclean