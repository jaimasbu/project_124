//main.c

#include <studio.h>
#include "stack.h"

#define MAX 100


int main () {
	
	// initialize files, variables, arrays
	FILE *maze_f;
	char maze[MAX][MAX];
	char ch;
	int i, j;
	
	// open input file
	if((maze_f = fopen("maze.txt", "r")) == NULL) {
		printf("Maze.txt cannot be opened.");
		exit (1);
	}
	
	// scan from input file to maze array
	while((ch=fgetc(maze_f))!=EOF){  //not end of file
		if(i == MAX){ //8 rows max
			i = 0; //reset when row 8 for column i is hit
			j++; //next column for each row
		}
		maze[i][j] = ch; 
		i++; //goes down the row for the same column
	}
	
	//user input for start/end
	
	
	//save good_path, store in output file
	
	//actual code
	
	fclose(maze_f);
	return 0;
}