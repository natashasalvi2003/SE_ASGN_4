#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include "listADT.h"
// #include "operations.h"
#include "postfix.h"

int main()
{
    char infix[MAX];
    printf("Enter the infix expression: ");
    gets(infix);
    number *res=(number *)malloc(sizeof(number));
    initnumber(res);
    // number *num1=(number *)malloc(sizeof(number));
    // number *num2=(number *)malloc(sizeof(number));
    // initnumber(num1);
    // initnumber(num2);
    // append(num1,'1');
    // append(num1,'0');
    // append(num2,'1');
    // append(num2,'0');
    // res=power(num1,num2);
    printf("Equivalent Postfix expression: \n");
    inToPost(infix);
    res=eval(postfix);
    printf("\nResult: ");
    printnumber(*res);

    return 0;

    

    



    // // number num1;
    // // number num2;
    // number *num1=(number *)malloc(sizeof(number));
    // number *num2=(number *)malloc(sizeof(number));
    // initnumber(num1);
    // initnumber(num2);
    // number *res=(number *)malloc(sizeof(number));
    // initnumber(res);
    // append(num1,'5');
    // append(num1,'0');
    // append(num2,'5');
    // append(num2,'5');
    // // int c=compare(*num1,*num2);
    // // printf("%d\n",c);
    // res=multiply(num1,num2);
    
    // node *p=num1->first;
    // if(num1->sign==MINUS)
    //     printf("-");
    // while(p)
    // {
    //     printf("%d",p->n);
    //     p=p->next;
    // }

    // printf(" one=%d ",one->first->n);

    // printf("%d ",iszero(*num1));
    // printf("%d ",iszero(*num2));
    // printf("Entered expression: ");
    // for (int i = 0; i < strlen(infix); i++)
    // {
    //     printf("%c",infix[i]);
    // }
    
    // printf("\nEquivalent Postfix expression: \n");
    // print(postfix);


    


    // num1.sign=PLUS;
    // num2.sign=PLUS;
    // append(&num1,'1');
    // append(&num1,'1');
    // append(&num1,'1');
    // append(&num2,'2');
    // append(&num2,'2');
    // append(&num2,'2');
    // res=add(&num1,&num2);
    // node *p;
    // p=res->first;
    // printf("sign=%d",res->sign);
    // while(p)
    // {
    //     printf("%d",p->n);
    //     p=p->next;
    // }


    
}