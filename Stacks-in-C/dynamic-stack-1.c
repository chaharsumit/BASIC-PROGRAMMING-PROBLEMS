#include<stdio.h>
#include<stdlib.h>
#define NULL 10
/* Structure template for Stack */
typedef struct{
  int *item;
  int top;
  int size;
}Stack;

/* Funtion Prototypes */
void init(Stack *, int );
void push(Stack *,int );
int pop(Stack *);
void deallocate(Stack *);


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

    printf("stack overflow\n");

  }


  sp->top++;
  sp->item[sp->top] = value;
}

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
}

int main()
{
  Stack s1;
  int choice,value;
  init(&s1,5);

  printf("1. Push\n2.Pop\n3.Exit\n");

  while(1){

    printf("Enter Your Choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
      /* Pushing into the array */
      case 1: printf("enter value\n");
              scanf("%d",&value);
              push(&s1,value);
              break;
      /* Performing Pop on the array */
      case 2: value = pop(&s1);
              if(value != -999)
              {
                printf("value popped out is - %d\n",value);
              }
              break;
      case 3: deallocate(&s1);
              exit(0);

      default: printf("Invalid Choice\n");
    }

  }

  return 0;
}
