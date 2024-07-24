# List of source files
SRCS =	main.cpp \
		PmergeMe.cpp

# Create a variable for the object directory
OBJDIR = obj

# Generate a list of object files with the obj/ prefix
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

NAME = PmergeMe

DEBUG_FLAG = 0

ifeq ($(DEBUG_FLAG),1)
    CXXFLAGS += -D DEBUG -fsanitize=address -g3 
else
    CXXFLAGS += -std=c++98
endif

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Create the obj/ directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Update the pattern rule to place .o files in the obj/ directory
ifeq ($(DEBUG_FLAG),1)
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -D DEBUG -I. $< -o $@
else 
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -I. $< -o $@
endif

all: $(NAME)

debug:
	make DEBUG_FLAG=1

clean:
	rm -rf $(OBJDIR)

fclean:
	make clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
