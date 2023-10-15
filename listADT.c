#include<stdio.h>
#include<stdlib.h>
#include "listADT.h"

void initnumber(number *a)
{
    // a=(number *)malloc(sizeof(number));
    a->first=NULL;
    a->dec = 0;
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

void zeroRemov(number *a) {
	node *p = a->first;
	int i, len = length(*a);
	for(i = 0; i < len - a->dec -1; i++) {
		if(p->n == 0) {
			a->first = p->next;
			p->next = NULL;
			a->first->prev = NULL;
			free(p);
			p = a->first;
		}else {
			break;
		}
	}
	p = a->last;
	int decimal = a->dec;
	for(i = 0; i < decimal - 1; i++) {
		if(p->n == 0) {
			a->last = p->prev;
			p->prev = NULL;
			a->last->next = NULL;
			free(p);
			p = a->last;
			a->dec--;
			
		}else {
			break;
		}
	}
	return;
}

void printnumber(number a)
{
    node *p;
    int pos = 0;
    zeroRemov(&a);
    p=a.first;
    if(a.sign==MINUS)
    {
        printf("-");
        a.sign = PLUS;
    }
    while (p)
    {
        pos++;
		if(pos == (length(a) - a.dec + 1))
			printf(".");
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

void remov(number *a, int pos){
	int i;
	node *p, *tmp;
	/* handle errors on position */	
	if(pos < 0 || pos >= length(*a))
		return;	
	
	p = a->first;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(a->first == NULL) {
		return;
	}
	if(length(*a) == 1) {	
		a->first = a->last = p = NULL;
		return;
	}
	if(pos == 0) {	
		p->next->prev = NULL;
		a->first = p->next;
		free(p);
		return;
	}
	if(pos == length(*a) - 1) {	
		tmp = p->next;
		p->next = NULL;
		a->last = p;
		free(tmp);
		return;
	}
	
	tmp = p->next;
	p->next = p->next->next;
	tmp->next->prev = p;	
	free(tmp);
	return;
}