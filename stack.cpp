#include <iostream>
#include "Header_calc.h"


int stack_init(stack* s)
{
	s->head = NULL;
	return 0;
}

int stack_is_empty(const stack* s)
{
	return !s->head;
}

int stack_push(stack* s, element val) {

	struct node* n = (node*)malloc(sizeof(struct node));
	if (!n) return -1;

	n->next = s->head;
	n->val = val;
	s->head = n;

	return 0;

}

void free_el(element_d* el) {
	el->val = NULL;
}

int pop(stack* s, element *val) {
	//val как-будто бы out
	if (s->head)
	{

		val = &(s->head->val); //написала какую-то хрень
		s->head = s->head->next;
		return 0;

	}
	else return -1;
}

int stack_free(stack* s) {
	
	while (pop(s, NULL) == 0);
	return 0;
}


void print_stack(stack* s) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp = s->head;


	while (tmp->next != NULL) {
		std::cout << tmp->val.val;
		tmp = tmp->next;
	}
}



//////////////

int stack_d_init(stack_d* s)
{
	s->head = NULL;
	return 0;
}

int stack_d_is_empty(const stack_d* s)
{
	return !s->head;
}

int stack_d_push(stack_d* s, element_d val) {

	struct node_d* n = (node_d*)malloc(sizeof(struct node_d));
	if (!n) return -1;

	n->next = s->head;
	n->val = val;
	s->head = n;

	return 0;

}

element_d* pop_d(stack_d* s, element_d* val) {
	//val как-будто бы out

	if (s->head != NULL) {
		val = &(s->head->val); //написала какую-то хрень
		s->head = s->head->next;
	}
	else std::cout << "Что-то пошло не так ";
		return val;


}

int stack_free(stack_d* s) {

	while (pop_d(s, NULL) == 0);
	return 0;
}


void print_stack_d(stack_d* s) {
	node_d* tmp = (node_d*)malloc(sizeof(node_d));
	tmp = s->head;


	while (tmp != NULL) {
		std::cout << tmp->val.val;
		tmp = tmp->next;
	}
}

//double take_the_last(stack_d* s) {
//
//	double res = 0;
//
//	node_d* tmp = (node_d*)malloc(sizeof(node_d));
//	tmp = s->head;
//
//	while (tmp->next != NULL) {
//		std::cout << tmp->val.val;
//		tmp = tmp->next;
//	}
//
//	res = tmp->next->val.val;
//	tmp->next = NULL;
//	
//}