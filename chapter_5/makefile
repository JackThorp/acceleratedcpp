CXX = g++
CXX_FLAGS = -Wall -g

EXE_NAME = pindex
BIN_DIR = ./bin
OBJ_DIR = $(BIN_DIR)/obj 

all: scaffold $(BIN_DIR)/$(EXE_NAME)

scaffold:
	@mkdir -p ./bin/obj
	echo "Object dir: " $(OBJ_DIR)

$(BIN_DIR)/$(EXE_NAME): $(OBJ_DIR)/index.o
	$(CXX) $(CXX_FLAGS) $< -o $@

$(OBJ_DIR)/index.o: permuted_index_3.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@
