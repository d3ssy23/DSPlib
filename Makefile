NAME = DSPlib.a

CC = g++

FLAGS = -Wall -Wextra -Werror

OBJ = 	$(SRC:.cpp=.o)

OBJDIR = build 

SRC = $(wildcard oscillators/*.cpp\
		effects/*.cpp \
		src/*.cpp \ )
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))


TARGET = dsp_build

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@
	

clean:
	rm -rf $(OBJ) $(TARGET)

.PHONY: all re clean fclean	

