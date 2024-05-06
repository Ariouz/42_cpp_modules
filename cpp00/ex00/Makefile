NAME= megaphone

SRCS= megaphone.cpp
OBJS= megaphone.o

FLAGS= -std=c++98 -Wall -Werror -Wextra

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean	
	make $(NAME)

all: $(NAME)

.PHONY: all re clean fclean