// actions.c

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

#define MAX 100

static position current;

// create switch statement later, meaning we only need one function, also current position doesn't need to be a stack

//mark ??
void mark(){
	current.x = '+';
	current.y= '+';
}

//move_f
void MOVE_F(){
	push(stack.x + 1);
}

//move_b
void MOVE_B{
	push(stack.x - 1);	
}

//move_l
void MOVE_L
{
	push(stack.y + 1);	
}

//move_r
void MOVE_R
{
	push(stack.y - 1);	
}



//full
int is_full(){
	if(top==MAX-1)
		return 1; //is full
	return 0; //not full
}

//empty
int is_empty(){
	if(top == 0)
		return 1;	//is empty
	return0; //not empty
}

// push (add or mark it)
void push (int x, int y)
{
	if(!is_full()) {
		stack.x[top] = x;
		stack.y[top] = y;
		top++;
	}
	
	else {
		print("memory full");
	}
}


//pop
void pop(){
	if(!is_empty()){
		stack--; 
	}
	exit(1);
}

//peek
int peek(){
	if(!is_empty()){
		return stack[top-1];
	}
}

//clear
void clear (){
	top = 0;
}








