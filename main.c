//Dylan, Jaima, Ray
//ESE 124 Final Project
//substring from string.h??

//main.c

#include <stdio.h>
#include <string.h>
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
	
	// get start and end positions from file
	fscanf(maze_f, "%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
	_initialize (start_x, start_y, end_x, end_y); //action file
	
	Printf("Start row:");
	scanf("%d", &start_x);

	Printf("Start col:");
	scanf("%d", &start_y);

	Printf("END row:");
	scanf("%d", &end_x);

	Printf("END col:");
	scanf("%d", &end_y);

	// get maze dimensions
	fseek(maze_f, 6, SEEK_SET);	
	while((ch = fgetc(maze_f)) != EOF) {
		if(nrcols == 0 && ch != '\n')		// counts number of characters in first row
			nrrows++;	// horizontal
		if(ch == '\n' || ch == EOF)			// counts number of rows until end of file
			nrcols++;	// vertical
	}
	//  int x_amt=0;
	//  if nrrow>nrcol,
	//  x_amt=nrrow;


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
	// j = 0;
	// // while(exitted == 0 && j < MAX_NUMBER_OF_STEPS) { //for repeat
	// // 	fscanf(intel_f, "%d %d %d", &com, &n, &t);
	// // 	_execute(com, n, t);
	// // 	j++;
	// // }

	 //while(memory[top].x != x2 && memory[top].y != y2) //check end position against the memory stack
	// 	//execeute lines 1-7
	// 	//store string in array from file
	// 	while(memory[top].x = a.x && memory[top].y = a.y) //current position was not in memeory stack
	// 	//peek at memory, check which direction he moved in, keep going in that direction
	// 	if(current position is right of original position)
	// 		move_r

	// 	if current position is down of original
	// 	move_b//lines 8-9
	// 	//peek at new position & save new position 

	// 	if current position is left of original
	// 	move_l

	// 	if current position is up of original	
	// 	move_f
	
	// 	if current == stack - 1
	// 		break;
	
	// 	if current == stack -1
	// 		//execute mark lines 
	// 		//execute lines 1-7
		
	// 	// print actions taken into output file
	// 	//points system maybe, counter for amount of steps taken
	// 	test();
	
	// if(st)
	//  int order;
    // while (fscanf(intel_f, "%d", &order) == 1) {
    //     switch (order) {
    //         case 2: // CWR
    //         case 3: // CWB
    //         case 4: // CWL
    //         case 5: // CWF
    //         case 15: // CJPI
    //             _execute(order, 0, 0); // Execute the action
    //             if (is_free_and_no_pheromone(current.x, current.y)) {
    //                 stack[++top] = current; // Store current position to stack
    //                 _execute(PUSH, 0, 0); // Push current position to stack
    //             }
    //             break;
    //             _execute(order, 0, 0); // Execute the action
    //             break;
    //         // Add more cases as needed for other actions
    //         default:
    //             fprintf(stderr, "Error: Invalid order found in intelligent file.\n");
    //             exit(EXIT_FAILURE);

				char com[10]
				while(!= (start_x== end_x && start_y !=end_y && K!=MAX_NUMBER_OF_STEPS))
				{
					fgets(com, 10, intel_f);
					if(strcmp(com, "MOVE_R") == 0) {
							//move_f
							//MOVE_R(Maze);
						_execute (MOVE_R); 
						printf("move right executed.\n");
						k++;
					}
					else if(strcmp(com, "MOVE_B") == 0){
						_execute (MOVE_B); 
						printf("move down executed.\n");
						k++;
					}
					else if(strcmp(com,"MOVE_L") == 0){
						//MOVE_L(Maze);
						_execute (MOVE_L); 
						printf("move left executed.\n");
						k++;
					}
					else if(strcmp(com,"MOVE_F") == 0){
						//MOVE_F(Maze);
						_execute (MOVE_F); 
						printf("move front executed.\n");
						k++;
					}
					else if(strcmp(com, "CWR") == 0) {
						//CWR(Maze)
						_execute (CWR); 
						printf("feel itch to right.\n");
						k++;
					}
					else if(strcmp(com, "CWB") == 0) {
						//CWB(Maze);
						_execute (CWB); 
						printf("feel itch to down.\n");
						k++;
					}
					else if(strcmp(com, "CWL") == 0) {
						//CWL(Maze);
						_execute (CWL); 
						printf("feel itch to left.\n");
						k++;
					}
					else if(strcmp(com, "CWF") == 0) {
						//CWF(Maze);
						_execute (CWF); 
						printf("feel itch to front.\n");
						k++;
					}
					else if(strcmp(com,"CJPI")==0){
						_execute (CWF); 
						printf("jump towards previous itch.\n");
						k++;
					}

				}//check infront of the wall 
				printf("number of moves made %d", k); //moves made

				int gdeeds=0; //total good deeds
				int gds=0; //current good deed
				if(maze[i][j] > '0' && maze[i][j] <= '9'){
					gds = maze[i][j];
					gdeeds += gds;
				}
				printf("Good Deeds: %d", gdeeds);

				
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
