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

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
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

int CountTwoDigit(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0, iNo = 0;

    temp = first;

    while(temp != NULL)
    {
        iNo = temp->data;

        if(iNo < 0)
        {
            iNo = -iNo; 
        }

        if(iNo >= 10 && iNo <= 99)
        {
            iCount++;
        }

        temp = temp->next;
    }

    return iCount;
}


int main()
{
    int iRet = 0;
    bool bRet = false;
    PNODE head = NULL;

    InsertFirst(&head, 151);
    InsertFirst(&head, 120);
    InsertFirst(&head, 111);
    InsertFirst(&head, 50);
    InsertFirst(&head, 20);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    iRet = CountTwoDigit(head);
    printf("Count of Two digit numbers from linked list are : %d\n", iRet);

    return 0;
}
