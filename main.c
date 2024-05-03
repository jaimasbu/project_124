//main.c

#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "variables.h"

#define MAX 100
#define MAX_NUMBER_OF_STEPS 100

int main() {
	
	// initialize files, variables, arrays
	FILE *maze_f, *intel_f, *outp_f;
	char ch;
	int i, j;
	
	// open files
	if((maze_f = fopen("maze.txt", "r")) == NULL) {
		printf("maze.txt cannot be opened.");
		exit (1);
	}
	
	/*if((intel_f = fopen("intel.txt", "r")) == NULL) {
		printf("intel.txt cannot be opened.");
		exit (1);
	}*/
	
	if((outp_f = fopen("output.txt", "w")) == NULL) {
		printf("output.txt cannot be opened.");
		exit (1);
	}

	// scan start and end positions from input file
	
	// get dimensions of maze
	while((ch = fgetc(maze_f)) != EOF) {
		if(nrrows == 0 && ch != '\n')		// counts number of characters in first row
			nrcols++;	// horizontal
		if(ch == '\n' || ch == EOF)			// counts number of rows until end of file
			nrrows++;	// vertical
	}
	
	// test print to check maze dimensions, delete later
	printf("%d %d\n\n", nrrows, nrcols);
	
	// scan from input file to maze array
	fseek(maze_f, 0, SEEK_SET);				// returns file pointer to beginning of file
	for(i = 0; i < nrrows; i++) {
        for(j = 0; j < nrcols; j++) {
            fscanf(maze_f, "%c", &maze[i][j]);
            if(maze[i][j] == '\n')			// removes any '\n' from the array
            	j--;						
        }
    }
	
	// test print to check if 2d array correctly stored maze, delete later
	for(i = 0; i < nrrows; i++) {
		for(j = 0; j < nrcols; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}
	
	// execute intelligence file
	
	// print actions taken into output file
	
	test();
	
	fclose(maze_f);
	//fclose(intel_f);
	fclose(outp_f);
	return 0;
}
