#include<stdio.h>
#define SIZE 10

/* Structure template for Stack */
typedef struct{
  int item[SIZE];
  int top;
}Stack;

/* Funtion Prototypes */
void init(Stack *);
void push(Stack *,int );
int  pop(Stack *);

/* initializing the top to -1 for structure variables */
void init(Stack *sp)
{
  sp->top = -1;
}

/* Defining Push and pop opeartions */

void push(Stack *sp,int value)
{
  if(sp->top == SIZE - 1)
  {
    printf("stack overflow\n");
  }

  sp->top++;
  sp->item[sp->top] = value;
}

int  pop(Stack *)
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



int main()
{
  Stack s1,s2;

  init(&s1);
  init(&s2);

  /* Pushing into the array */
  push(&s1,100);
  push(&s1,200);

  push(&s2,10);
  push(&s2,20);

  /* Performing Pop on the array */
  pritnf("popped out %d\n",pop(&s1));
  pritnf("popped out %d\n",pop(&s1));

  pritnf("popped out %d\n",pop(&s2));
  pritnf("popped out %d\n",pop(&s2));

  return 0;
}