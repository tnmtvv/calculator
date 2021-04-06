// calc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <cstring>
#include <malloc.h>
#include "Header_calc.h"



int main()
{

    setlocale(LC_ALL, "Russian");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    int n = 100;
    char* equation = (char*)malloc(n * sizeof(char));
    
    element* op = (element*)malloc(sizeof(element));

    element e;
    element_d e_d;

    double a, b;
    a = 0;
    b = 0;

    int if_integ = 1;

    node* tmp = (node*)malloc(sizeof(node));
    stack_d* x = (stack_d*)malloc(sizeof(stack_d));
    stack* y = (stack*)malloc(sizeof(stack));

    //char* num = (char*)malloc(n * sizeof(char));
    int j = 0;

    int iterator = 5;
    //if_correct = 1;
    int min_to_double =1;
    int diff = 0;
    while (iterator) {
        
        stack_d_init(x);
        stack_init(y);

        printf("\nВведите выражение\n");
        std::cin >> equation;
        int i = 0;
        if (equation[0] == '-')
        {
            min_to_double = 1;
            i = 1;
        }
        for (i; i < n; i += j) {
            if (equation[i] >= 48 && equation[i] <= 57)
            {
                j = i;

                while (equation[j] >= 48 && equation[j] <= 57 || equation[j] == ',' || equation[j] == 'e')
                {
                    if (equation[j] == 'e')
                        j += 4;
                    else j++;
                }






                diff = j - i;


                char num[100]; //просто максимально костыльно, потому что не выделяется массив этот тупой того размера, какой нужен


                for (int i = 0; i < n; i++) {
                    num[i] = '\0';
                }

                for (int k = i; k < j; k++) {
                    /* if (equation[k] == '.')
                         if_integ = 0;*/
                    num[k - i] = equation[k];
                }

                /*if (if_integ) {
                    num[j - i] = '.';
                }*/

                //memcpy(num, &equation[i], (j-i));
                if (min_to_double) {

                    e_d.val = atof(num) * (-1);
                    min_to_double = 0;
                }
                else e_d.val = atof(num);

                memset(num, 0, n);

                stack_d_push(x, e_d);
                std::cout << e_d.val;
                std::cout << ' ';
                j = diff;

            }
                  
           else if (equation[i] == '(' || equation[i] == '+' || equation[i] == '-'|| equation[i] == '*' || equation[i] == '/')//умнее было бы наверное написать строку со всеми операциями и сравнивать символ с каждым из строки, 
            {
                j = 1;
                e.val = equation[i];
                switch (equation[i]) {
                case '+':
                    e.priority = 3;
                    break;
                case '-':
                    e.priority = 3;
                    break;
                case '*':
                    e.priority = 4;
                    break;
                case '/':
                    e.priority = 4;
                    break;
                case '(':
                    
                    e.priority = 2;
                    if (equation[i + 1] == '-') {
                        min_to_double = 1;
                        j++;
                    }
                    break;
                    /*case '=':
                        e.priority = 1;
                        break;*/
                }
                if(y->head != NULL && y->head->val.priority <= e.priority) {

                    stack_push(y, e);

                }
                else if (y->head != NULL && y->head->val.priority > e.priority&& e.val != '(') {
                    //do_op(x, y->head->val.val, a, b, &e_d);
                    stack_d_push(x, do_op(x, y->head->val.val, a, b, &e_d, &iterator));
                    std::cout << y->head->val.val;
                    std::cout << ' ';
                    pop(y, op);

                    stack_push(y, e);


                }
                else {
                    stack_push(y, e);
                }
            }

            else if (equation[i] == ')' || '=' && y->head != NULL) {
                j = 1;
                tmp = y->head;
                if (e.val != '(') {
                    while ((char)tmp->val.val != '(' && y->head->val.priority <= e.priority)//возможно do while
                    {

                        stack_d_push(x, do_op(x, tmp->val.val, a, b, &e_d, &iterator));
                        pop(y, &e);//меняем то, на что указывает голова
                        std::cout << tmp->val.val;
                        std::cout << " ";
                        tmp = y->head;
                        if (y->head == NULL)
                            break;

                    }
                }
                else 
                    while ((char)tmp->val.val != '(')//возможно do while
                    {

                        stack_d_push(x, do_op(x, tmp->val.val, a, b, &e_d, &iterator));
                        pop(y, &e);//меняем то, на что указывает голова
                        std::cout << tmp->val.val;
                        std::cout << " ";
                        tmp = y->head;
                        if (y->head == NULL)
                            break;

                    }

                pop(y, &e);//удаляем скобочку

            }
            else break;

        }
        std::cout << "\n";

        print_stack_d(x);
    }
    //std::cout << "\n";
    //print_stack(x);

     



    //std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
