# CS315 Makefile for Program 2: ternary
# Feel free to modify as needed.
# Original author: Raphael Finkel 1/2020
Edited by: Andrew Jones

CFLAGS = -Wall -g
CPPFLAGS = -Wall -g
GOAL = ternary

NUMPOINTS = 1000
SEED = 49
LIMIT = 10000

# compile and run the student program, placing the result in tmpRun.out
run: $(GOAL) randGen.pl
	./randGen.pl $(SEED) $(LIMIT) | ./$(GOAL) $(NUMPOINTS) > tmpRun.out
	less tmpRun.out


# get the randGen.pl program
randGen.pl:
	wget http://www.cs.uky.edu/~raphael/courses/CS315/utils/randGen.pl
	chmod +x randGen.pl


	
.PHONY: clean
clean:
	rm -f randGen.pl $(GOAL) workingTernary tmp* toSubmit.zip
