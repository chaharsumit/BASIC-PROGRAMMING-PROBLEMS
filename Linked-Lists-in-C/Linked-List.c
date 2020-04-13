#include<stdio.h>
#include<stdlib.h>
#define NULL 0

typedef struct linked_list{
    int number;
    struct linked_list *next;
}node;

    void create_list(node *ptr);
    void print_list(node *ptr);
    int count_nodes(node *ptr);

int main()
{
    node *head;



    head = (node *)malloc(sizeof(node));

    create_list(head);

    printf("\n");

    print_list(head);

    printf("\n");

    printf("The number of nodes in the list are - %d",count_nodes(head));
    
    /*free up the space allocated*/
    
    free(head);
    
    return 0;
}

void create_list(node *list)
{
    printf("enter the number\nprint -999 to end\n");
    scanf("%d",&list->number);

    if(list->number == -999)
    {
        list->next == NULL;
    }

    else
    {
        list->next = (node *)malloc(sizeof(node));
        create_list(list->next);
    }

    return;

}

void print_list(node *list)
{
    if(list->next != NULL)
    {
        printf("%d-->",list->number);

        if(list->next->next == NULL)
        {
            printf("%d",list->next->number);
        }

        print_list(list->next);
    }

    return;
}

int count_nodes(node *list)
{
    if(list->next == NULL)
    {
        return (0);
    }
    else
    {
        return(1+count_nodes(list->next));
    }
}
