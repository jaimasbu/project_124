// actions.c

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "variables.h"

#define MAX 100

// the way I think we can implement this is that each action will be assigned a number by us, for example mark will be 1, move_f will be 2, etc, and that will be how we select the action in the switch statement, it will require us to
// to write the intelligence file in numbers, but that shouldn't be too bad

static position backtrack, current, end;
int x = 0, itch_F = 0, itch_B = 0, itch_L = 0, itch_R = 0;
int i, j;

// initialize ant starting and end positions
void initialize (position a, position b) {
	
	// starting position
	current.x = a.x;
	current.y = a.y;
	
	// ending position
	end.x = b.x;
	end.y = b.y;
	
}

void test () {
	
	printf("\nactions.c\n");
	printf("%d %d\n\n", nrrows, nrcols);
	
	int i, j;
	
	for(i = 0; i < nrrows; i++) {
		for(j = 0; j < nrcols; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}

}


// for some reason in this project x represents up and down and y represents left and right, so moving in x means moving up or down the maze's rows and moving in y means moving left or right on the maze's coloumn.
// quite confusing for me, essentially x corresponds to rows, y corresponds to columns: maze[row][column] / maze[x][Y]

void execute (int a, int b, int c) {
	
	switch (a) {
		
		// MARK
		case 1: {
			maze[current.x][current.y] = '+';		// mark ant's current position in the maze with a + representing pheromone
			break;
		}
		
		// MOVE_F
		case 2: {
			if(maze[current.x + 1][current.y] != '*')		// check for walls
				current.x++;								// add 1 to x, y is unchanged
			break;
		}
		
		// MOVE_B
		case 3: {
			if(maze[current.x - 1][current.y] != '*')
				current.x--;								// subtract 1 from x, y is unchanged
			break;
		}
		
		// MOVE_L
		case 4: {
			if(maze[current.x][current.y - 1] != '*')
				current.y--;								// x is unchanged, subtract 1 from y
			break;
		}
		
		// MOVE_R
		case 5: {
			if(maze[current.x + 1][current.y + 1] != '*')
				current.y++;								// x is unchanged, add 1 to y
			break;
		}
		
		// CWL
		case 6: {
			i = 0;
			itch_L = 1; 
			while(maze[current.x][current.y - i] != '*') {		// checks positions to the left of the ant
				if(maze[current.x][current.y - i] == '+')		// checks if any positions to the left of the ant is marked, if so then itch flag is set to 0
					itch_L = 0;
				x++;											// number of spaces until it reaches a wall
				i++;
			}
			break;
		}
		
		// CWR
		case 7: {
			i = 0;
			itch_R = 1; 
			while(maze[current.x][current.y + i] != '*') {		// same deal as CWL
				if(maze[current.x][current.y + i] == '+')
					itch_R = 0;
				x++;
				i++;
			}
			break;
		}
		
		// CWF
		case 8: {
			i = 0;
			itch_F = 1; 
			while(maze[current.x + i][current.y] != '*') {		// same deal as CWL
				if(maze[current.x + i][current.y] == '+')
					itch_F = 0;
				x++;
				i++;
			}
			break;
		}
		
		// CWB
		case 9: {
			i = 0;
			itch_B = 1; 
			while(maze[current.x - i][current.y] != '*') {		// same deal as CWL
				if(maze[current.x - i][current.y] == '+')
					itch_B = 0;
				x++;
				i++;
			}
			break;
		}
		
		// PUSH
		case 10: {
			push(current);
			break;
		}
		
		// POP
		case 11: {
			backtrack = pop();			// retrieve coords from top of memory
			break;
		}
		
		// PEEK
		case 12: {
			backtrack = peek();			// retrieve coords from top of memory
			break;
		}
		
		// CLEAR
		case 13: {
			clear();
			break;
		}
		
		// BJPI
		case 14: {
			if(itch_F) {				// check which itch is enabled
				current.x += x;			// moves x spaces in the direction of the itch
				itch_F = 0;				// disables the itch
				x = 0;					// resets x for the next CW_ 
			}
			else if(itch_B) {			// same deal
				current.x -= x;
				itch_B = 0;
				x = 0;
			}
			else if(itch_L) {			// same deal
				current.y -= x;
				itch_L = 0;
				x = 0;
			}
			else if(itch_R) {			// same deal
				current.y += x;
				itch_R = 0;
				x = 0;
			}
			else {						// if no itch, do nothing
			}
			break;
		}
		
		// CJPI
		case 15: {
			if(itch_F) {				// check which itch is enabled
				current.x += 1;			// moves 1 space in the direction of the itch
				itch_F = 0;				// disables the itch
				x = 0;					// resets x for the next CW_ 
			}
			else if(itch_B) {			// same deal
				current.x -= 1;
				itch_B = 0;
				x = 0;
			}
			else if(itch_L) {			// same deal
				current.y -= 1;
				itch_L = 0;
				x = 0;
			}
			else if(itch_R) {			// same deal
				current.y += 1;
				itch_R = 0;
				x = 0;
			}
			else {						// if no itch, do nothing
			}
			break;
		}
		
		// BACKTRACK
		case 16: {
			current = backtrack;		// set Michael's current position to the backtrack position
			break;
		}
		
		// RP
		case 17: {
			break;
		}
		
		// invalid input
		default: {
			printf("Invalid Command.");
			exit(1);
		}
	}
}
