SRC 	= testePWM
CPP  	= g++
FLAGS	= -std=c++0x -O0 -g3 -Wall
EXEC 	= executavel
DEP1 	= ../includes/v3.0/BlackCore
DEP2 	= ../includes/v3.0/BlackPWM

all:		$(DEP1).o $(DEP2).o
		$(CPP) $(FLAGS) $(SRC).cpp $(DEP1).o $(DEP2).o -o $(EXEC)

BlackCore.o:	$(DEP1).cpp $(DEP1).h
		$(CPP) $(FLAGS) -c $(DEP1).cpp -o $(DEP1).o

BlackPWM.o:	$(DEP2).cpp $(DEP2).h
		$(CPP) $(FLAGS) -c $(DEP2).cpp -o $(DEP2).o

clean: 
		rm ../include/v3.0/*.o *~
		
