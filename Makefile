SRCS = $(shell find -name '*.cpp')

CC = g++
LD = ld
CFLAGS = -std=c++20 -Wall -g
LDFLAGS = -lGL -lglfw -lGLEW

ourcraft: $(SRCS)
	$(CC) $^ -o $@ $(LDFLAGS) 

clean:
	rm ourcraft
