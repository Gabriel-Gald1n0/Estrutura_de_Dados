#RODA NO MINGW64!!! <--
CC := gcc
CFLAGS := -Wall -std=c99 -pedantic -O3
OUT_DIR := build
SRC_DIR := src
INC_DIR := include

# Default target
all: $(OUT_DIR)/Q1.exe $(OUT_DIR)/Q2.exe

# Build Q1.exe
$(OUT_DIR)/Q1.exe: $(SRC_DIR)/Q1.c $(OUT_DIR)/Biblioteca1.o | $(OUT_DIR)
	$(CC) -o $@ $(SRC_DIR)/Q1.c $(OUT_DIR)/Biblioteca1.o $(CFLAGS) -I$(INC_DIR)

# Build Biblioteca1.o
$(OUT_DIR)/Biblioteca1.o: $(SRC_DIR)/Biblioteca1.c | $(OUT_DIR)
	$(CC) -c $(SRC_DIR)/Biblioteca1.c -o $@ -I$(INC_DIR)

# Build Q2.exe
$(OUT_DIR)/Q2.exe: $(SRC_DIR)/Q2.c $(OUT_DIR)/Biblioteca2.o | $(OUT_DIR)
	$(CC) -o $@ $(SRC_DIR)/Q2.c $(OUT_DIR)/Biblioteca2.o $(CFLAGS) -I$(INC_DIR)

# Build Biblioteca2.o
$(OUT_DIR)/Biblioteca2.o: $(SRC_DIR)/Biblioteca2.c | $(OUT_DIR)
	$(CC) -c $(SRC_DIR)/Biblioteca2.c -o $@ -I$(INC_DIR)

# Create output directory
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Run Q1
run1: $(OUT_DIR)/Q1.exe
	$(OUT_DIR)/Q1.exe

# Run Q2
run2: $(OUT_DIR)/Q2.exe
	$(OUT_DIR)/Q2.exe

# Clean up
clean:
	rm -f $(OUT_DIR)/*.o $(OUT_DIR)/*.exe
