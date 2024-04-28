//stack.c

#include <stdio.h>
#include "queue.h"
#define MAX 100

static position stack[MAX];
static int top=-1;

//clear
void clear (){
	top = 0;
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
void push (int a)
{
	if(!is_full()) {
		stack[top] = a;
		top++;
	}
	else {
		print("Already marked")
	}
}
//mark
void mark(){
	
}

