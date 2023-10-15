#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "postfix.h"

int ct=0;
// number *postfix[MAX];
stack S1;
void initstack(stack *S,int s)
{
    // S->p=(number *)malloc(sizeof(number)*s);
    S->size=s;
    S->top=-1;
    return;
}

int isFullstack(stack S)
{
    return (S.top == S.size - 1);
}

int isEmptystack(stack S)
{
    return (S.top == -1);
}

void spush(stack *S, number *k)
{
    if(isFullstack(*S))
        return;
    S->top+=1;
    // printf("p");
    // printf("top=%d\n",S->top);
    S->p[S->top]=k;
    return;
}

number *spop(stack *S)
{
    // printf("pop");
    if (isEmptystack(*S))
        return NULL;
    number *g=S->p[S->top];
    (S->top)--;
    return g;
}

int precedence(char c)
{
    switch (c)
    {

        case '^':
            return 3;
        case '/': case '%': case '*':
            return 2;
        case '+':case '-':
            return 1;
        default:
            return 0;
    }
}

int space(char c)
{
    if(c==' ' || c=='\t')
    {
        return 1;
    }
    return 0;
}

void inToPost(char B[])
{
    initstack(&S1,100);
    int i,j=0,k=0,flag=0;
    char sym;
    number *y;
    number *t;
    number *op;
    // number *y=(number *)malloc(sizeof(number));
    // initnumber(y);
    // number *t=(number *)malloc(sizeof(number));
    // initnumber(t);
    number *temp1=(number *)malloc(sizeof(number));
    initnumber(temp1);
    if(B[0]=='-')
    {
        k=1;
        flag=1;
    }
    for(i=k;i<strlen(B);i++)
    {
        
        sym=B[i];
        // printf("%c",sym);
        if(!space(sym))
        {
            switch(sym)
            {
                case '+': case '/': case '*': case '-': case '^': case '%': 
                    // postfix[j++]=temp1;
                    if(B[i+1]=='-')
                    {
                        flag=1;
                        i++;
                    }
                    op=(number *)malloc(sizeof(number));
                    initnumber(op);
                    append(op,sym);
                    // printnumber(*op);
                    if(!isEmptystack(S1))
                        y=(S1.p[S1.top]);
                    
                    while(!isEmptystack(S1) && (precedence((y->first)->n))>=(precedence(sym)))
                    {
                        postfix[j++]=spop(&S1);
                        y=(S1.p[S1.top]);
                    }
                    spush(&S1,op);
                    // printf("%c",S1.p[S1.top]->first->n);
                    // printf("c");
                    break;
                case '(':
                    op=(number *)malloc(sizeof(number));
                    initnumber(op);
                    if(B[i+1]=='-')
                    {
                        flag=1;
                        i++;
                    }
                    append(op,sym);
                    spush(&S1,op);
                    break;
                case ')':
                    t=spop(&S1);
                    while((t->first->n)!='(')
                    {
                        // printf("%c",t->first->n);
                        postfix[j++]=t;
                        t=spop(&S1);
                        // printf("%c",t->first->n);
                    }
                    break;
                default:
                    append(temp1,sym);
                    if(B[i+1] < '0' || B[i+1] > '9')
                    {
                        if(flag==1)
                        {
                            temp1->sign=MINUS;
                            flag=0;
                        }
                        postfix[j++]=temp1;
                        
                        temp1=(number *)malloc(sizeof(number));
                        initnumber(temp1);
                    }
                    break;
            }
        }
    }
    // postfix[j++]=temp1;
    // printf("%d %d",postfix[j-1]->first->n,postfix[j-1]->last->n);
    while(!isEmptystack(S1))
    {
        postfix[j++]=spop(&S1);
    }
    ct=j;

    //printing;
    node *pr;
    for(int m=0;m<ct;m++)
    {
        pr=(postfix[m])->first;
        if(postfix[m]->sign==MINUS)
            printf("-");
        // printf("%d\n",pr->n);
        while(pr)
        {
            if((pr->n)>10)
            {
                printf("%c",pr->n);
            }
            else if((pr->n)>=0 && (pr->n)<=9)
            {
                printf("%d",pr->n);
            }
            pr=pr->next;
        }
        printf(" ");
    }
}

// void print(number *C[])
// {
//     node *p;
//     for(int i=0;i<ct;i++)
//     {
//         // printf("%d",m);
//         p=C[i]->first;
//         while(p!=NULL)
//         {

//             if((p->n)>10)
//                 printf("%c ",p->n);
//             else
//                 printf("%d ",p->n);
//             p=p->next;
//         }
//     }
//     return;
// }


number *eval(number *C[])
{
    number *r=(number *)malloc(sizeof(number));
    initnumber(r);
    initstack(&S1,100);
    int sym;
    for(int i=0;i<ct;i++)
    {
        node *w=C[i]->first;
        if((w->n)>=0 && (w->n)<=9)
        {
            spush(&S1,C[i]);
            // printf("%d\n",(S1.p[S1.top])->first->n);
        }
        else
        {
            
            number *a1=spop(&S1);
            number *a2=spop(&S1);
            // printf("f ");
            // printnumber(*a1);
            // printnumber(*a2);
            sym=w->n;
            // printf("%c",sym);
            switch(sym)
            {
                case 43: //add
                    // printf("\na");
                    r=add(a2,a1);
                    spush(&S1,r);
                    // printnumber(*r);
                    r=NULL;
                    // printf("c ");
                    break;
                case 45: //subtract
                    // printf("\ns");
                    r=sub(a2,a1);
                    spush(&S1,r);
                    // printnumber(*r);
                    r=NULL;
                    break;
                case 42:  //multiply
                    // printf("\nm");
                    r=multiply(a2,a1);
                    spush(&S1,r);
                    // printnumber(*r);
                    r=NULL;
                    break;
                case 47:  //division
                    // printf("\nd");
                    r=divide(a2,a1);
                    spush(&S1,r);
                    // printnumber(*r);
                    r=NULL;
                    break;
                case 94:
                    // printf("\np");
                    r=power(a2,a1);
                    spush(&S1,r);
                    // printnumber(*r);
                    r=NULL;
                    break;
                case 37: //modulus
                    r=mod(a2,a1);
                    spush(&S1,r);
                    r=NULL;
                    break;
                default:
                    break;
            }
        }
    }
    
    return spop(&S1);
}