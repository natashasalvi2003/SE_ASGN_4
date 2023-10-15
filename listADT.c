#include<stdio.h>
#include<stdlib.h>
#include "listADT.h"

void initnumber(number *a)
{
    // a=(number *)malloc(sizeof(number));
    a->first=NULL;
    a->last=NULL;
    a->sign=PLUS;
    return;
}

// void initnode(node *p)
// {
//     p=(node *)malloc(sizeof(node));
//     if(!p)
//         return;
// }

int length(number a)
{
    node *p;
    int ct=0;
    p=a.first;
    while(p!=NULL)
    {
        ct++;
        p=p->next;
    }
    return ct;
}

void printnumber(number a)
{
    node *p=a.first;
    if(a.sign==MINUS)
        printf("-");
    while (p)
    {
        printf("%d",p->n);
        p=p->next;
    }
    return;
}

void append(number *a, char ch)
{
    // printf("%c",ch);
    node *nn=(node *)malloc(sizeof(node));
    if(!nn)
        return;
    if(ch >= '0' && ch <= '9')
    {
        nn->n=ch-'0';
    }
    else if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='(' || ch=='^'|| ch=='%')
    {
        nn->n=ch;
    }
    else
    {
        free(nn);
        return;
    }
    nn->next=NULL;
    if(!a->first && !a->last)
    {

        nn->prev=NULL;
        a->first=nn;
        a->last=nn;
        return;
    }
    nn->prev=a->last;
    a->last->next = nn;
    a->last=nn;
    return;
}


void push(number *a,int key)
{
    if(key < 0 || key > 9)
        return;
    node *nn=(node *)malloc(sizeof(node));
    if(!nn)
        return;
    nn->n=key;
    nn->prev=NULL;
    if(a->first==NULL && a->last==NULL)
    {
        nn->next=NULL;
        a->first=nn;
        a->last=nn;
        return;
    }
    nn->next=a->first;
    a->first->prev=nn;
    a->first=nn;
    return;
}

