#############################
#                           #
#  Makefile for ServoDriver #
#  Executable: servodriver  #
#                           #
#                           #
#############################

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lwiringPi

all: servodriver

servodriver: servodriver.o
	$(CC) $(LDFLAGS) servodriver.o -o servodriver

servodriver.o: servodriver.c
	$(CC) $(CFLAGS) servodriver.c
clean:
	rm -rf *.o  servodriver
