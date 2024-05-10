NAME= interface

SRCS= main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp
OBJS= $(SRCS:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

all:
	make $(NAME)

re:
	make fclean
	make $(NAME)

.PHONY: all re clean fclean