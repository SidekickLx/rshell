CC = g++
ROOT_DIR = $(shell pwd)
export CC BIN OBJS_DIR ROOT_DIR
all:
	make -C src
