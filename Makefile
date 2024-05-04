CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++20 -Wall -I$(INCLUDE_DIR) -g
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EXECUTABLE_FILE = pvz.out

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/PVZ.o \
	$(BUILD_DIR)/Menu.o \

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/utils.hpp $(INCLUDE_DIR)/Defs.hpp $(INCLUDE_DIR)/PVZ.hpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

$(BUILD_DIR)/PVZ.o: $(SRC_DIR)/PVZ.cpp $(INCLUDE_DIR)/PVZ.hpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/PVZ.cpp -o $(BUILD_DIR)/PVZ.o

$(BUILD_DIR)/Menu.o: $(SRC_DIR)/Menu.cpp $(INCLUDE_DIR)/Menu.hpp
	$(CC) $(CFLAGS) $(LFLAGS) -c $(SRC_DIR)/Menu.cpp -o $(BUILD_DIR)/Menu.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out