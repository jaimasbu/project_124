//Dylan, Jaima, Ray
//ESE 124 Final Project
// actions.c

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "variables.h"

#define MAX 1000

// the way I think we can implement this is that each action will be assigned a number by us, for example mark will be 1, move_f will be 2, etc, and that will be how we select the action in the switch statement, it will require us to
// to write the intelligence file in numbers, but that shouldn't be too bad

static position current, backtrack, end;
static int x = 0, itch_F = 0, itch_B = 0, itch_L = 0, itch_R = 0;
int i, j, count, repetitions, rep_flag, rep_size, *rep_list, *rep_pos;
int actions[MAX];

// initialize ant starting and end positions
void _initialize (int a, int b, int c, int d) {
	
	// starting position
	current.x = a;
	current.y = b;
	
	// ending position
	end.x = c;
	end.y = d;
	
	// initiallize michael status
	exitted = 0;
	
}

// prototype repeat
void repeat(int *list, int n, int t);

void test () {
	printf("\nactions.c\n");
	printf("%d %d\n\n", nrrows, nrcols);
	
	int i, j;
	
	for(i = 0; i < nrcols; i++) {
		for(j = 0; j < nrrows; j++)
			printf("%c", maze[i][j]);
		printf("\n");
	}

}

// for some reason in this project x represents up and down and y represents left and right, so moving in x means moving up or down the maze's rows and moving in y means moving left or right on the maze's coloumn.
// quite confusing for me, essentially x corresponds to rows, y corresponds to columns: maze[row][column] / maze[y][x]


void _execute (char namestring[10]) {
	
	switch (a) {
		
		// MARK
		case 'MARK': {
			maze[current.y][current.x] = '+';		// mark ant's current position in the maze with a + representing pheromone
			if(rep_flag == 1 && count < rep_size) {		// check if repeat function has been called, adds action to repeat array if so
				*rep_list = 1;
				rep_list++;
			}	
		}

void MOVE_F() {
			if(maze[current.y][current.x + 1] != '*')		// check for walls
				current.x++;								// add 1 to x, y is unchanged
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 2;
				rep_list++;
			}
}

void MOVE_B(){
			if(maze[current.y][current.x - 1] != '*')
				current.x--;								// subtract 1 from x, y is unchanged
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 3;
				rep_list++;
			}
		}
void MOVE_L(){
			if(maze[current.y - 1][current.x] != '*')
				current.y--;								// x is unchanged, subtract 1 from y
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 4;
				rep_list++;
			}
		}
void  MOVE_R() {
			if(maze[current.y + 1][current.x] != '*')
				current.y++;								// x is unchanged, add 1 to y
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 5;
				rep_list++;
			}

void RP() {
			rep_flag = 1;
			count = 0;
			rep_size = b;
			repetitions = c;
			rep_list = (int*) malloc (rep_size * sizeof(int));		// create dynamic array for actions to repeat
			rep_pos = rep_list;										// store beginning position for array
}

void BACKTRACK() {
			current = backtrack;		// set Michael's current position to the backtrack position
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 16;
				rep_list++;
			}
}

void CJPI() {
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
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 15;
				rep_list++;
			}
}

void _execute (char namestring[10]) {
	
	switch (a) {
		
		// MARK
		case 'MARK': {
			_execute(MARK);
			break;	
		}
		
		// MOVE_F
		case 'MOVE_F': {
			_execute(MOVE_F);
			break;
		}
		
		// MOVE_B
		case 'MOVE_B': {
			_execute(MOVE_B);
			break;
		}
		
		// MOVE_L
		case 'MOVE_L': {
			_execute(MOVE_L);
			break;
		}
		
		// MOVE_R
		case 'MOVE_R': {
			_execute(MOVE_R);
			break;
		}
		
		// CWL
		case 'CWL': {
			i = 0;
			itch_L = 1; 
			while(maze[current.y - i][current.x] != '*') {		// checks positions to the left of the ant
				if(maze[current.y - i][current.x] == '+')		// checks if any positions to the left of the ant is marked, if so then itch flag is set to 0
					itch_L = 0;
				x++;											// number of spaces until it reaches a wall
				i++;
			}
			if(x == 0)
				itch_L = 0;
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 6;
				rep_list++;
			}
			break;
		}
		
		// CWR
		case 'CWR': {
			i = 0;
			itch_R = 1; 
			while(maze[current.y + i][current.x] != '*') {		// same deal as CWL
				if(maze[current.y + i][current.x] == '+')
					itch_R = 0;
				x++;
				i++;
			}
			if(x == 0)
				itch_R = 0;
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 7;
				rep_list++;
			}
			break;
		}
		
		// CWF
		case 'CWF': {
			i = 0;
			itch_F = 1; 
			while(maze[current.y][current.x + 1] != '*') {		// same deal as CWL
				if(maze[current.y][current.x + 1] == '+')
					itch_F = 0;
				x++; 
				i++;
			}
			if(x == 0)
				itch_F = 0;
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 8;
				rep_list++;
			}
			break;
		}
		
		// CWB
		case 'CWB': {
			i = 0;
			itch_B = 1; 
			while(maze[current.y][current.x - i] != '*') {		// same deal as CWL
				if(maze[current.y][current.x - i] == '+')
					itch_B = 0;
				x++;
				
				i++;
			}
			if(x == 0)
				itch_B = 0;
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 9;
				rep_list++;
			}
			break;
		}
		
		// PUSH
		case 'PUSH': {
			push(current);
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 10;
				rep_list++;
			}
			break;
		}
		
		// POP
		case 'POP': {
			backtrack = pop();			// retrieve coords from top of memory
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 11;
				rep_list++;
			}
			break;
		}
		
		// PEEK
		case 'PEEK': {
			backtrack = peek();			// retrieve coords from top of memory
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 12;
				rep_list++;
			}
			break;
		}
		
		// CLEAR
		case 'CLEAR': {
			clear();
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 13;
				rep_list++;
			}
			break;
		}
		
		// BJPI
		case 'BJPI': {
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
			if(rep_flag == 1 && count < rep_size) {		
				*rep_list = 14;
				rep_list++;
			}
			break;
		}
		
		// CJPI
		case 'CJPI': {
			_execute(CJPI);
			break;
		}
		
		// BACKTRACK
		case 'BACKTRACK': {
			_execute(BACKTRACK);
			break;
		}
		
		// RP
		case 'RP': {
			_execute(RP);									// store beginning position for array
			break;
		}
		
		// invalid input
		default: {
			printf("Invalid Command.");
			exit(1);
		}
	}
 
	if(current.x == end.x && current.y == end.y)				// check if michael is at end location
		exitted = 1;
	
	if(rep_flag == 1 && count == rep_size - 1) {				// check if repeat function is compelete
		rep_list = rep_pos;										// go to start of repeat array
		rep_flag = 0;						
		repeat(rep_list, rep_size, repetitions);			
	}
}

void repeat(int *list, int n, int t) {
	
	int k, l;
	
	for (l = 0; l < t; l++) {
		list = rep_pos;		
		for (k = 0; k < n; k++, list++)					
			_execute(*list, 0, 0);
	}
	free(list);											
	
}
