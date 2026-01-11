NAME = Zombie

SRCS = main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \

OBJS = ${SRCS:.cpp=.o}
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

.c.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME} 

re: fclean all

.PHONY : all clean fclean re