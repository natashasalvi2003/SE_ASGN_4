#include<stdio.h>
#include "listADT.h"
#define SCALE 31
number *one;
int eqlength(number *a, number *b);
void decimalEqual(number *a, number *b);
int iszero(number a);
number *add(number *a, number *b);
number *sub(number *a, number *b);
number *multiply(number *a, number *b);
number *multiply2(number *a, number *b);
number *divide(number *a, number *b);
number *divide2(number *a, number *b);
int compare(number *a,number *b);
number *sub1(number *a, number *b);
number *power(number *a,number*b);
number *mod(number *a, number *b);
number *factorial(number *a);