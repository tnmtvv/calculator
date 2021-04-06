#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Header_calc.h"

double operation(char sign, double val_1, double val_2, int* it) {
	switch (sign) {
	case '+':
		return val_1 + val_2;
		break;
	case'-':
		return val_2 - val_1;
		break;
	case'*':
		return val_1 * val_2;
		break;
	case'/':
		if (val_1)
			return val_2 / val_1;
		else {
			system("cls");
			std::cout << "Что-то пошло не так ";
			it = 0;
			return 0;
		}
		break;
	}
}

element_d do_op(stack_d* x, char op, double a, double b, element_d* e_d, int* it) {
	element_d e;

	e_d = pop_d(x, e_d);
	a = e_d->val;

	free_el(e_d);

	e_d = pop_d(x, e_d);
	b = e_d->val;

	e.val = operation(op, a, b, it);
	
	return e;
}



