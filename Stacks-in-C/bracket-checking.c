#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100
/* Structure template for Stack */
typedef struct{
  char item[SIZE];
  int top;
}Stack;

/* Funtion Prototypes */
void push(Stack *,char );
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *);
int isOpeningMatch(char, char);
int checkExpr(char[]);


/*Function definitions*/

/*Pushing the values in the stack*/
void push(Stack *sp,char value)
{
        if(sp->top == SIZE-1)
        {
            printf("stack Overflow\n");
            exit(1);
        }

        sp->item == value;
        sp->top++;
}

/*pop operation for popping out the brackets when needed*/
char pop(Stack *sp)
{
    if(isEmpty(sp))
    {
        printf("stack Underflow\n");
        exit(1);
    }

    return sp->item;
    sp->top--;

}

/*checking if stack if empty or not*/
int isEmpty(Stack *sp)
{
    return sp->item == -1;
}

/*obtaining top of the stack if stack is not empty*/
char stacktop(Stack *)
{
    if(isEmpty(sp))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return sp->item[sp->top];
}

/*Checking if the new character matches with the one on top of the stack*/
int isOpeningMatch(char left, char right)
{
    int match = 0;

    switch(left)
    {
        case '(': if(right == ')'){
                        match = 1;
                    }
        case '{': if(right == '}'){
                        match = 1;
                    }
        case '[': if(right == ']'){
                        match = 1;
                    }
        default: printf("wrong invalid character entered\n");
                 exit(1);
    }
    return match;
}

/*performing the expression checking on the items in the stack*/
int checkExpr(char expr[])
{
    Stack stack;
    stack.top = -1;
    int error = 0;

    int counter = 0;
    while(expr[counter]!='\0')
    {
        char next_char = expr[counter];
        if(next_char == '(' || next_char == '{' || next_char == '[')
        {
            push(&stack,next_char);
        }

        else if(next_char == ')' || next_char == '}' || next_char == ']')
        {
            if(isEmpty(&stack))
            {
                error = 1;
                break;
            }
        }

        else if(isOpeningMatch(stacktop(&stack),next_char)){
            pop(&stack);
        }

        else
        {
            error = 1;
            break;
        }


        counter++;

    }

    if(!error && !isEmpty(&stack))
        {
            error = 1;
        }

        return error;

}

/*Main program*/
int main()
{
    char expr[SIZE];
    printf("Input the expression\n");
    scanf("%s",expr);

    if(checkExpr(expr))
    {
        printf("The expression is not well formed\n");
    }
    else
    {
        printf("The expression is a well formed expression\n");
    }

    return 0;
}
