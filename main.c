//Dylan, Jaima, Ray
//ESE 124 Final Project
//substring from string.h??

//main.c

#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "variables.h"

#define MAX 100
#define MAX_NUMBER_OF_STEPS 1000

int main() {
	
	// initialize files, variables, arrays
	FILE *maze_f, *intel_f, *outp_f;
	char ch;
	int i, j;
	int com, n, t;
	int start_x, start_y, end_x, end_y;
	
	// open files
	if((maze_f = fopen("maze.txt", "r")) == NULL) {
		printf("maze.txt cannot be opened.");
		exit (1);
	}
	
	if((intel_f = fopen("intel.txt", "r")) == NULL) {
		printf("intel.txt cannot be opened.");
		exit (1);
	}
	
	if((outp_f = fopen("output.txt", "w")) == NULL) {
		printf("output.txt cannot be opened.");
		exit (1);
	}
	
	// get start and end positions
	fscanf(maze_f, "%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
	_initialize (start_x, start_y, end_x, end_y); //action file
	
	// get maze dimensions
	fseek(maze_f, 6, SEEK_SET);	
	while((ch = fgetc(maze_f)) != EOF) {
		if(nrcols == 0 && ch != '\n')		// counts number of characters in first row
			nrrows++;	// horizontal
		if(ch == '\n' || ch == EOF)			// counts number of rows until end of file
			nrcols++;	// vertical
	}
	
	// test print to check maze dimensions, delete later
	printf("%d %d\n\n", nrrows, nrcols);
	
	// scan from input file to maze array
	fseek(maze_f, 6, SEEK_SET);				// returns file pointer to beginning of maze
	for(i = 0; i < nrcols; i++) {
        for(j = 0; j < nrrows; j++) {
            fscanf(maze_f, "%c", &maze[i][j]);
            if(maze[i][j] == '\n')			// removes any '\n' from the array
            	j--;						
        }
    }
	
	// test print to check if 2d array correctly stored maze, delete later
	for(i = 0; i < nrcols; i++) {
		for(j = 0; j < nrrows; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}
	
	// execute intelligence file
	j = 0;
	while(exitted == 0 && j < MAX_NUMBER_OF_STEPS) { //for repeat
		fscanf(intel_f, "%d %d %d", &com, &n, &t);
		_execute(com, n, t);
		j++;
	}

	while(memory[top].x != x2 && memory[top].y != y2) //check end position against the memory stack
		
		//execeute lines 1-7
		//store string in array from file
		while(memory[top].x = a.x && memory[top].y = a.y) //current position was not in memeory stack
		//peek at memory, check which direction he moved in, keep going in that direction
		if(current position is right of original position)
			move_r

		if current position is down of original
		move_b//lines 8-9
		//peek at new position & save new position 

		if current position is left of original
		move_l

		if current position is up of original	
		move_f
	
		if current == stack - 1
			break;
	
		if current == stack -1
			//execute mark lines 
			//execute lines 1-7
		
		// print actions taken into output file
		//points system maybe, counter for amount of steps taken
		test();
	
		fclose(maze_f);
		fclose(intel_f);
		fclose(outp_f);
		return 0;
}

fgets(
	//string compare to ee which case 

	//on top of number, get row n column and reads as good deed value and is stored to total good deeds, 
	//after its done moving but before doing next move, -'0'
)

//while not max steps
//read line from inetlligence file
//comapres it to the function, excecute move_f(maze)
