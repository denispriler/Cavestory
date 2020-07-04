#CC specifies which compiler we're using
CC := g++

SRC_DIR := ./src
INC_DIR := ./include
LIB_DIR := ./lib

SRCS := $(shell find $(SRC_DIR) -name *.cpp)

INC_DIRS := $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIB_DIRS := $(shell find $(LIB_DIR) -type d)
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -m64 -Wall -Wextra -pedantic-errors # -Werror

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS := -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Cavestory

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(SRCS) $(COMPILER_FLAGS) $(INC_FLAGS) $(LIB_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)