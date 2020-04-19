#include<stdio.h>
#include<stdlib.h>
#define NULL 10
/* Structure template for Stack */
typedef struct{
  int *item;
  int top;
  int size;
}Stack;

/*----------------------------------------------------------------------------*/

/* Funtion Prototypes */
void init(Stack *, int );
void push(Stack *,int );
int pop(Stack *);
void deallocate(Stack *);
int getSize(Stack *);


/*get the current size of stack*/
int getSize(Stack *sp)
{
    return sp->size;
}


/* initializing the top to -1 for structure variables */
void init(Stack *sp, int size)
{

  sp->top = -1;

  sp->item = (int *)malloc(sizeof(int) * size);

  if(sp->item == NULL)
  {

    exit(1);

  }

  sp->size = size;


}

/* Defining Push and pop opeartions */

void push(Stack *sp,int value)
{
  if(sp->top == sp->size - 1)
  {

    int *temp;
    temp = (int *)malloc(sizeof(int) * sp->size * 2);
    if(temp == NULL)
    {
        printf("stack overflow\n");
    }

    for(int i = 0 ; i <= sp->top ; i++)
    {
        temp[i] = sp->item[i];
    }
    free(sp->item);

    sp->item = temp;
    sp->size *= 2;

  }


  sp->top++;
  sp->item[sp->top] = value;
}

/*function to pop items from the stack*/
int pop(Stack *sp)
{

  if(sp->top == -1)
  {

    printf("stack underflow\n");
    return -999;

  }

  int value;
  value = sp->item[sp->top];
  sp->top--;
  return value;

}

/*
    free up memory space when all operations are performed
*/

void deallocate(Stack *sp)
{
    if(sp->item != NULL)
    {
        free(sp->item);
    }

    sp->top = -1;
    sp ->size = 0;

}
/*------------------------------------------------------------------------*/

void printBinary(unsigned int);



int main()
{

  printBinary(19);

  return 0;

}

/*Function for converting decimal to binary*/

void printBinary(unsigned int n)
{
    Stack s;
    unsigned int temp = n;
    const int BASE = 2;
    init(&s,10);
    int result;

    while(n>0)
    {
       result =  n % BASE;
       push(&s,result);
       n /= BASE;
    }

    printf("binary equivalent for %d is: \n",temp);

    while(s.top != -1)
    {

        printf("%d",pop(&s));

    }

    deallocate(&s);

}
