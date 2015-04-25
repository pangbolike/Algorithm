SRC_DIR=src/
OBJ_DIR=
LIB_DIR=

OBJ_EXT=.o
CPPSRC_EXT=.cpp
INC+=-I./include
LIB+=
BUILD=main

OBJECTS = $(patsubst $(SRC_DIR)%$(CPPSRC_EXT), $(OBJ_DIR)%$(OBJ_EXT),$(wildcard $(SRC_DIR)*$(CPPSRC_EXT)))

$(OBJ_DIR)%$(OBJ_EXT):$(SRC_DIR)%$(CPPSRC_EXT)
	@echo -e "\033[1;33m\nCompiling $< ==> $@ \033[0m..."
	$(CXX) $(INC) -c $<  -o $@ $(LIB)
	@echo ""

$(BUILD) : $(OBJECTS)
	@echo -e "\033[1;33m\nCompiling $(OBJECTS) ==> $@ \033[0m..."
	$(CXX) $(OBJECTS) -o $(BUILD)
all:$(BUILD)
	strip $(BUILD)
clean:
	rm -rf $(OBJECTS) $(BUILD)

