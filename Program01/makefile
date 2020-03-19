#
# PROGRAM:    assign1
# PROGRAMMER: victor amaro
# LOGON ID:   z1747708
# DATE DUE:  2-04-16
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
