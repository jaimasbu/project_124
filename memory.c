//Dylan, Jaima, Ray
//ESE 124 Final Project
// memory.c

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#define MAX_SIZE 100

// stack
static position memory[MAX_SIZE];
static int top;

// stack functions

void clear () {
	
	top = 0;
	
}

int is_full () {
	
	if(top == MAX_SIZE - 1)
		return 1;	// is full
	else
		return 0;	// not full
		
}

int is_empty () {
	
	if(top == 0)
		return 1;	// is empty
	else
		return 0;	// not empty
}

void push (position a) {
	
	if(!is_full()) {
		memory[top].x = a.x;
		memory[top].y = a.y;
		top++;
	}
	
	else {
		printf("Error: Stack is full.");
		exit (1);
	}
	
}

position pop () {
	
	position temp;
	
	if(!is_empty()) {
		temp = memory[top - 1];
		top--; 
		return temp;
	}
	else {
		printf("Error: Stack is empty.");
		exit (1);
	}
	
}

position peek () {
	
	return memory[top - 1];
	
}
