#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// #include "listADT.h"
#include "operations.h"
#define MAX 1000

// typedef node *List;
number *postfix[MAX];
typedef struct stack
{
    number *p[MAX];
    int size;
    int top;
}stack;

void initstack(stack *S,int s);
void spush(stack *S, number *k);
number *spop(stack *S);
void inToPost(char B[]);
// void print(number *C[]);
number *eval(number *C[]);

