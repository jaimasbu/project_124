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
	while(exitted == 0 && j < MAX_NUMBER_OF_STEPS) {
		fscanf(intel_f, "%d %d %d", &com, &n, &t);
		_execute(com, n, t);
		j++;
	}
	
	//
	// print actions taken into output file
	
	test();
	
	fclose(maze_f);
	fclose(intel_f);
	fclose(outp_f);
	return 0;
}
