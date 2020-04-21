#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NULL 10
/* Structure template for Stack */
typedef struct{
  char *item;
  int top;
  int size;
}Stack;

/* Funtion Prototypes */
void init(Stack *, int );
void push(Stack *,char );
char pop(Stack *);
void deallocate(Stack *);
int getSize(Stack *);
void deallocate(Stack *);
int isUnderflow(Stack *);
int isOverflow(Stack *);


/*Functions to check for underflow and overflow*/
int isOverflow(Stack *sp)
{
    sp->top == sp->size- 1;
}

int isUnderflow(Stack *sp)
{
    sp->top == -1;
}

/*get the current size of stack*/
int getSize(Stack *sp)
{
    return sp->size;
}


/* initializing the top to -1 for structure variables */
void init(Stack *sp, int size)
{

  sp->top = -1;

  sp->item = (char *)malloc(sizeof(char) * size);

  if(sp->item == NULL)
  {

    exit(1);

  }

  sp->size = size;


}

/* Defining Push and pop opeartions */

void push(Stack *sp,char value)
{
  if(sp->top == sp->size - 1)
  {

    char *temp;
    temp = (char *)malloc(sizeof(char) * sp->size * 2);
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
char pop(Stack *sp)
{

  if(sp->top == -1)
  {

    printf("stack underflow\n");
    return '\0';

  }

  char value;
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

/*Function for printing the reverse of content of file to the other file*/

int reverseFile(char inp[], char out[])
{
    FILE *fps,*fpd;

    const int SIZE = 50;

    fps = fopen(inp, "r");

    if(fps == NULL)
    {
        printf("error opening file %s\n",inp);
        return 0;
    }
    fpd = fopen(out, "w");

    if(fpd == NULL)
    {
        printf("error opening file %s\n",out);
        return 0;
    }

    Stack s;
    init(&s,SIZE);
    char buffer;

    buffer = fgetc(fps);

    while(!feof(fps))
    {
        push(&s,buffer);
        buffer = fgetc(fps);
    }

    while(!isUnderflow(&s))
    {
        fputc(pop(&s),fpd);
    }

    fclose(fps);
    fclose(fpd);
    deallocate(&s);


    return 1;

}

int main()
{
  int f = reverseFile("input.txt","reverse.txt");
  if(f)
  {
    printf("file copied successfully\n");
  }
  else
  {
    printf("error occured\n");
  }

  return 0;
}
