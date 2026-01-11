NAME = PhoneBook

SRCS = Contact.cpp \
		main.cpp \
		PhoneBook.cpp \

OBJS = ${SRCS:.cpp=.o}
INCLUDE = PhoneBook.hpp
CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = rm -f

.c.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@

${NAME}: ${OBJS} $(INCLUDE)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME} 

re: fclean all

.PHONY : all clean fclean re