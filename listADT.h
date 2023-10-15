#include<stdio.h>
#define PLUS 1
#define MINUS -1

typedef struct node
{
    int n;
    struct node *next, *prev;
}node;

typedef struct number
{
    int sign, dec;
    node *first, *last;
}number;

void initnumber(number *a);
void push(number *a, int key);
void append(number *a, char ch);
int length(number a);
void printnumber(number a);
void zeroRemov(number *a);
void remov(number *a, int pos);
// void appendop(number *a, char ch);