#pragma once

typedef struct element {
	char val;
	int priority;
}element;

typedef struct element_d {
	double val;
}element_d;

typedef struct node {
	element val;
	node* next;
}node;

typedef struct node_d {
	element_d val;
	node_d* next;
}node_d;

typedef struct stack {
	struct node* head;
}stack;

typedef struct stack_d {
	struct node_d* head;
}stack_d;


void free_el(element_d* e_d);


int stack_init(stack *s);
int stack_is_empty(const stack* s);
int stack_push(stack* s, element val);
int pop(stack* s, element* val);
void print_stack(stack* s);



int stack_d_init(stack_d* s);
int stack_d_is_empty(const stack_d* s);
int stack_d_push(stack_d* s, element_d val);
element_d* pop_d(stack_d* s, element_d* val);
void print_stack_d(stack_d* s);
//double take_the_last(stack_d* s);

double operation(char sign, double val_1, double val_2, int* it);
element_d do_op(stack_d* x, char op, double a, double b, element_d* e_d, int* it);
//int if_correct;