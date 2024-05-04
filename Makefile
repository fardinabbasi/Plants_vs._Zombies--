CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++20 -Wall -I$(INCLUDE_DIR) -g

EXECUTABLE_FILE = pvz.out

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

OBJECTS = $(BUILD_DIR)/main.o


$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/utils.hpp $(INCLUDE_DIR)/Defs.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out