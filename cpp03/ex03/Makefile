NAME= claptrap

SRCS= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS= $(SRCS:.cpp=.o)

FLAGS= -Wall -Wextra -Werror -std=c++98 -Wno-shadow

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