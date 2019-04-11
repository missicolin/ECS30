cell.o: cell.c cell.h
	gcc -c cell.c
list.o: list.c cell.h list.h
	gcc -c list.c
cell_grid.o: cell_grid.c cell_grid.h
	gcc -c cell_grid.c
brians_brain.o: brians_brain.c 
	gcc -c brians_brain.c
cell_tester: cell_tester.c cell.o
	gcc -Wall -o cell_tester cell_tester.c cell.o -lm
list_tester: list_tester.c list.o cell.o
	gcc -Wall -o list_tester list_tester.c list.o cell.o
cell_grid_tester: cell_grid_tester.c cell_grid.o cell.o
	gcc -Wall -o cell_grid_tester cell_grid_tester.c cell_grid.o cell.o
brians_brain_cellular_automata: brians_brain_cellular_automata.c brians_brain.o cell.o cell_grid.o list.o
	gcc -Wall -o brians_brain_cellular_automata brians_brain_cellular_automata.c brians_brain.o cell.o cell_grid.o list.o 

clean:
	rm *.o brians_brain_cellular_automata cell_grid_tester list_tester cell_tester
all: cell.o list.o cell_grid.o brians_brain.o cell_tester list_tester cell_grid_tester brians_brain_cellular_automata
