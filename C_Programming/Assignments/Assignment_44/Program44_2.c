#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int iNO)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNO;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    PNODE temp = NULL;

    temp = first;

    printf("\n");

    while(temp != NULL)
    {
        printf("| %d | -> ", temp -> data);
        temp = temp -> next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        iCount++;
        temp = temp -> next;
    }
    
    return iCount;
}

int CountEven(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0;

    temp = first;

    while(temp != NULL)
    {
        if((temp -> data % 2) == 0)
        {
            iCount++;
        }

        temp = temp -> next;
    }

    return iCount;
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head, 121);
    InsertFirst(&head, 112);
    InsertFirst(&head, 54);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    iRet = CountEven(head);
    printf("Number of even elements from the linked list are : %d\n", iRet);

    return 0;
}
