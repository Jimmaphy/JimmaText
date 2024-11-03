# Define the compiler
CC = cl

# Define the source and output directories
SRC_DIR = src
BIN_DIR = bin

# Define the source file and output executable
SRC = $(SRC_DIR)\main.c
OUT = $(BIN_DIR)\jtext.exe

# Ensure the bin directory exists and compile the source file
all:
    if not exist $(BIN_DIR) mkdir $(BIN_DIR)
    $(CC) /nologo /W4 /O2 /EHsc $(SRC) /Fe:$(OUT)