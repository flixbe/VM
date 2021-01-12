CC     := gcc
CFLAGS := -Wall -g

TARGET   = main
SOURCES := $(wildcard src/*.c)

all: build

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm ./main