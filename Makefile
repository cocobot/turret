#Set ausbee directory path. Can be relative or absolute
AUSBEE_DIR=../../ausbee/

#List all source files
PROJECT_SRC_FILES=$(wildcard *.c)

#Include main Makefile
include $(AUSBEE_DIR)/Makefile
