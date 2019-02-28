# set flags for all warnings (Warngings all) and debug info
CXX = g++
CXX_FLAGS = -std=c++11 -Wall -g

# finalgrade: finalgrade.o median.o student.o grade.o
#	 ${CXX} ${CXX_FLAGS} ./build/finalgrade.o ./build/median.o ./build/student.o ./build/grade.o -o ./build/finalgrade

# finalgrade.o: finalgrade.cpp median.hpp
# 	${CXX} ${CXX_FLAGS} -c finalgrade.cpp -o ./build/finalgrade.o

# median.o: median.cpp median.hpp
# 	${CXX} ${CXX_FLAGS} -c median.cpp -o ./build/median.o

# student.o: student.cpp student.hpp
# 	${CXX} ${CXX_FLAGS} -c student.cpp -o ./build/student.o

# grade.o: grade.cpp grade.hpp
# 	${CXX} ${CXX_FLAGS} -c grade.cpp -o ./build/grade.o

EXE_NAME = finalgrade

SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = $(BIN_DIR)/obj

INCLUDES = ./includes

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)/*.cpp)) 
OBJ_PATHS = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o) 

.PHONY: clean build all

build: scaffold $(BIN_DIR)/$(EXE_NAME) 

print:
	@echo "Source files: " $(SRC_FILES)
	@echo "Object paths: " $(OBJ_PATHS)

scaffold:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BIN_DIR)

# $^ prereq list
$(BIN_DIR)/$(EXE_NAME) : $(OBJ_PATHS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

# Static pattern rule.
# target objects list: target object pattern match: prerequisites
# $< is first prerequisite
$(OBJ_PATHS): $(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDES) -c $< -o $@


