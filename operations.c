#include<stdio.h>
#include<stdlib.h>
#include "operations.h"


// number *one;

//dont do malloc when you just want to point to something else
int eqlength(number *a, number *b)
{
    
    int diff=length(*a)-length(*b);
    if(diff>0)
    {
        // printf("l");
        for(int i=0; i<diff;i++)
        {
            push(b,0);
        }
    }
    else if(diff<0)
    {
        diff=(-1)*diff;
        for(int i=0; i<diff;i++)
        {
            push(a,0);
        }
    }
    return length(*b);
}

int iszero(number a)  //return 0 when number is zero
{
    int flag=0;
    node *p=a.first;
    while(p!=NULL)
    {
        if(p->n!=0)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    return flag;
}

number *add(number *a, number *b)
{
    // printnumber(*a);
    // printnumber(*b);

    // number *result;
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
    // int l=eqlength(a,b);
    if(a->sign != b->sign) 
    {
		if(a->sign == MINUS) 
        {
			a->sign = PLUS;
			result = sub(b, a);
		}
		else if(b->sign == MINUS) 
        {
			b->sign = PLUS;
			result = sub(a, b);
		}
	}
	else if(a->sign == b->sign) 
    {
        result->sign=a->sign;
        int n1,n2,sum,carry=0,l1,l2;
        l1=length(*a);
        l2=length(*b);
        node *t1=a->last;
        node *t2=b->last;
        if(l1>l2)
        {
            for(int i=1;i<=l2;i++)
            {
                n1=t1->n;
                n2=t2->n;
                sum=n1+n2+carry;
                carry=sum/10;
                sum=sum%10;
                push(result,sum);
                t1=t1->prev;
                t2=t2->prev;
            }
            for(int i = 1; i <= l1 - l2; i++) {
				n1 = t1->n;
				sum = n1 + carry;
				carry = sum / 10;
				sum = sum % 10;
				push(result, sum);
				t1 = t1->prev;
			}
        }
        else
        {
            for(int i=1;i<=l1;i++)
            {
                n1=t1->n;
                n2=t2->n;
                // printf("%d",n1);
                // printf("%d",n2);
                sum=n1+n2+carry;
                // sum=t1->n +t2->n + carry;
                carry=sum/10;
                sum=sum%10;
                push(result,sum);
                t1=t1->prev;
                t2=t2->prev;
                // printf("t1= %d ",t1->n);
                // printf("t2= %d ",t2->n);
            }
            // printf("a"); //control not coming here
            for(int i = 1; i <= l2 - l1; i++) 
            {
                n1 = t2->n;
                sum = n1 + carry;
                carry = sum / 10;
                sum = sum % 10;
                push(result, sum);
                t2 = t2->prev;
            }
            
        }
        // printf("a");
        if(carry!=0)
            push(result,carry);
    }
    // printf("a");
    
    return result;
}

int compare(number *a, number *b)
{
    node *p, *q;
    int l1=length(*a);
    int l2=length(*b);
    p=a->first;
    q=b->first;
    if(l1 > l2)
        return 1;    //a is greater than b
    else if(l2 > l1)
        return -1;   //b is greater than a
    else
        for(int i=1;i<=l1;i++)
        {
            if(p->n > q->n)
                return 1;
            else if (p->n < q->n)
                return -1;
            else
                p=p->next;
                q=q->next;
        }
    return 0;    //they are equal
}

number *sub(number *a, number *b)
{
    // number *result;
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
    int l=eqlength(a,b);

    if(a->sign != b->sign)
    {
        if(a->sign==MINUS)
        {
            a->sign=PLUS;
            result=add(a,b);
            result->sign=MINUS;
        }
        if(b->sign==MINUS)
        {
            b->sign=PLUS;
            result=add(a,b);
            result->sign=PLUS;
        }
    }
    else if(a->sign == b->sign)
    {
        if(a->sign==MINUS)
        {
            a->sign=b->sign=PLUS;
            result=sub(b,a);
        }
        else if(a->sign==PLUS)
        {
            int c=compare(a,b);
            int n1, n2,diff,borrow=0,l1,l2;
            l1=length(*a);
            l2=length(*b);
            node *t1=a->last;
            node *t2=b->last;
            if(c==1)
            {
                for(int i=1;i<=l;i++)
                {
                    n1=t1->n;
                    n2=t2->n;
                    n1=n1-borrow;
                    if(n1>=n2)
                    {
                        diff=n1-n2;
                        borrow=0;
                        push(result,diff);
                    }
                    else
                    {
                        n1=n1+10;
                        diff=n1-n2;
                        borrow=1;
                        push(result,diff);
                    }
                    t1=t1->prev;
                    t2=t2->prev;
                }
                result->sign=PLUS;
            }
            else if(c==-1)
            {
                result->sign=MINUS;
                for(int i=1;i<=l;i++)
                {
                    n1=t1->n;
                    n2=t2->n;
                    n2=n2-borrow;
                    if(n2>=n1)
                    {
                        diff=n2-n1;
                        borrow=0;
                        push(result,diff);
                    }
                    else
                    {
                        n2=n2+10;
                        diff=n2-n1;
                        borrow=1;
                        push(result,diff);
                    }
                    t1=t1->prev;
                    t2=t2->prev;
                }
                
            }
            else 
            {
                if(c == 0)
                {
                    push(result,0);
                    result->sign=PLUS;
                }
            }
        }
    }
    return result;
}

number *sub1(number *a, number *b)
{
    // number *result;
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
    // int l=eqlength(a,b);

    if(a->sign != b->sign)
    {
        if(a->sign==MINUS)
        {
            a->sign=PLUS;
            result=add(a,b);
            result->sign=MINUS;
        }
        if(b->sign==MINUS)
        {
            b->sign=PLUS;
            result=add(a,b);
            result->sign=PLUS;
        }
    }
    else if(a->sign == b->sign)
    {
        if(a->sign==MINUS)
        {
            a->sign=b->sign=PLUS;
            result=sub(b,a);
        }
        else if(a->sign==PLUS)
        {
            int c=compare(a,b);
            int n1, n2,diff,borrow=0,l1,l2;
            l1=length(*a);
            l2=length(*b);
            node *t1=a->last;
            node *t2=b->last;
            if(c==1)
            { //c=1 means a>b,i.e.,l1>=l2
                for(int i=1;i<=l2;i++)
                {
                    n1=t1->n;
                    n2=t2->n;
                    n1=n1-borrow;
                    if(n1>=n2)
                    {
                        diff=n1-n2;
                        borrow=0;
                        push(result,diff);
                    }
                    else
                    {
                        n1=n1+10;
                        diff=n1-n2;
                        borrow=1;
                        push(result,diff);
                    }
                    t1=t1->prev;
                    t2=t2->prev;
                }
                for(int i=1;i<=(l1-l2);i++)
                {
                    n1=t1->n;
                    diff=n1-borrow;
                    borrow=0;
                    push(result,diff);
                    t1=t1->prev;
                }
                result->sign=PLUS;
            }
            else if(c==-1)
            {
                // l2>=l1,b>a
                result->sign=MINUS;
                for(int i=1;i<=l1;i++)
                {
                    n1=t1->n;
                    n2=t2->n;
                    n2=n2-borrow;
                    if(n2>=n1)
                    {
                        diff=n2-n1;
                        borrow=0;
                        push(result,diff);
                    }
                    else
                    {
                        n2=n2+10;
                        diff=n2-n1;
                        borrow=1;
                        push(result,diff);
                    }
                    t1=t1->prev;
                    t2=t2->prev;
                }
                for(int i=1;i<=(l2-l1);i++)
                {
                    n2=t2->n;
                    diff=n2-borrow;
                    borrow=0;
                    push(result,diff);
                    t2=t2->prev;
                }
                
            }
            else 
            {
                if(c == 0)
                {
                    push(result,0);
                    result->sign=PLUS;
                }
            }
        }
    }
    return result;
}

number *multiply(number *a, number *b)
{
    int temp;
    // number *x;
    // number *x=(number *)malloc(sizeof(number));
    // initnumber(x);
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
   
    one=(number *)malloc(sizeof(number));
    initnumber(one);
    append(one,'1');
    // printf(" one=%d ",one->first->n);
    if(iszero(*a)==0 || iszero(*b)==0)
    {
        append(result,'0');
        return result;
    }
   
    if(a->sign == b->sign)
        temp=1;
    else 
        temp=-1;

    a->sign=PLUS;
    b->sign=PLUS;
    result->sign=PLUS;
    // x->sign=PLUS;

    append(result,'0');

    // append(x,'0');
    while(iszero(*b)==1)
    {
        result=add(result,a);
        b=sub(b,one);
        // printnumber(*b);
        // printf("\n");
    }
    if(temp==1)
        result->sign=PLUS;
    else if(temp==-1)
        result->sign=MINUS;
    return result;
}


number *power(number *a,number*b)
{
    int temp;
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
   
    one=(number *)malloc(sizeof(number));
    initnumber(one);
    append(one,'1');
    if(iszero(*a)==0)
    {
        append(result,'0');
        return result;
    }
    if(iszero(*b)==0)
    {
        append(result,'1');
        return result;
    }
    result->sign=PLUS;
    append(result,'1');
    while(iszero(*b)==1)
    {
        result=multiply(result,a);
        b=sub(b,one);
        // printnumber(*b);
        // printf("\n");
    }
    return result;
}

number *divide(number *a, number *b)
{
    int s;
    number *quotient=(number *)malloc(sizeof(number));
    initnumber(quotient);

    if(iszero(*b)==0)
        return NULL;
    if(iszero(*a)==0)
    {
        append(quotient,'0');
        return quotient;
    }

    one=(number *)malloc(sizeof(number));
    initnumber(one);
    append(one,'1');

    number *temp=(number *)malloc(sizeof(number));
    initnumber(temp);
    if(a->sign == b->sign)
        s=1;
    else 
        s=-1;
    a->sign=PLUS;
    b->sign=PLUS;
    quotient->sign=PLUS;

    append(quotient,'0');
    temp=a;
    // int c=compare(*temp,*b);
    while((compare(temp,b)) >= 0) 
    {
        // printf("p");
        temp=sub(temp,b);
        quotient=add(quotient,one);
        // c=compare(*temp,*b);
    }
    
    // while(c == 1)
    // {
    //     temp=sub(temp,b);
    //     quotient=add(quotient,one);
    // }
    // if(compare(*temp,*b)==0)
    // {
    //     quotient=add(quotient,one);
    // }

    if(s==1)
        quotient->sign=PLUS;
    else if(s==-1)
        quotient->sign=MINUS;
    return quotient;
}

number *divide2(number *m, number *n)
{
    if(zeroNumber(*n) == 0) {
		printf("Dividing by Zero is not allowed.\n");
		return NULL; 
	}
	zeroRemov(m);
	zeroRemov(n);
	
	int k = m->dec > n->dec ? m->dec : n->dec;
	int i = 0;
	
	while(i < k) {
		if(m->dec > 0)
			m->dec--;
		else
			addDigit(m, '0');
		if(n->dec > 0)
			n->dec--;
		else
			addDigit(n, '0');
		i++;
	}
	i = 9;
	number *c, *d, *ans, *q, *pro;
	c = (number *)malloc(sizeof(number));
	d = (number *)malloc(sizeof(number));
	ans = (number *)malloc(sizeof(number));
	pro = (number *)malloc(sizeof(number));
	q = (number *)malloc(sizeof(number));
	
	initNumber(ans);
	initNumber(c);
	initNumber(q);
	initNumber(d);
	if(m->sign == n->sign) {
		q->sign = PLUS;
		m->sign = n->sign = PLUS;
	}
	else {
		q->sign = MINUS;
		m->sign = n->sign = PLUS;
	}
	node *p = m->first;
	char ch = p->n + '0';
	addDigit(d, ch);
	while(q->dec < SCALE){
		while(i >= 0){	
			appendleft(c, i);
			pro = mult(n, c);
			ans = sub(d, pro);	
			if(ans->sign != MINUS) {
				addDigit(q, i + '0');
				node *tmp = c->first;
				free(tmp);
				c->last = c->last = NULL;
				break;
			}
			else{
				node *tmp = c->first;
				free(tmp);
				c->first = c->last = NULL;
				i--; 
			}
		}
		d = ans;
		if(p->next != NULL) {
			p = p->next;
			ch = p->n + '0';
			addDigit(d, ch);
		}
		else{	
			q->dec++;	
			addDigit(d, '0');
		}
		i = 9;
		node *tmp = c->first;
		free(tmp);
		c->first = c->last = NULL;
	}
	q->dec--;
	return q;
}

number *mod(number *a, number *b)
{
    int s;
    number *quotient=(number *)malloc(sizeof(number));
    initnumber(quotient);
    number *result=(number *)malloc(sizeof(number));
    initnumber(result);
    
    if(iszero(*b)==0)
        return NULL;
    if(iszero(*a)==0)
    {
        append(result,'0');
        return result;
    }

    if(a->sign==MINUS)
        s=-1;
    if(a->sign==PLUS)
        s=1;
    // printf("s=%d",s);
    
    one=(number *)malloc(sizeof(number));
    initnumber(one);
    append(one,'1');

    a->sign=PLUS;
    b->sign=PLUS;

    append(quotient,'0');
    quotient->sign=PLUS;
    
    number *temp=(number *)malloc(sizeof(number));
    initnumber(temp);
    temp=a;
    while((compare(temp,b)) >= 0) 
    {
        temp=sub(temp,b);
        quotient=add(quotient,one);
    }
    // printnumber(*temp);
    // quotient=divide(a,b);
    // temp=multiply(quotient,b);
    // result=sub(a,temp);
     
    if(s==1)
        temp->sign=PLUS;
    else if(s==-1)
        temp->sign=MINUS;
    return temp;
}



