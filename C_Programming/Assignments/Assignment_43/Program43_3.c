#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node * Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Next = NULL;
    newn -> Data = No;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> Next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->", first -> Data);
        first = first -> Next;
    }
    
    printf("NULL\n");
}

int AdditionEven(PNODE first)
{
    int iSum = 0, iNo = 0;

    while(first != NULL)
    {
        iNo = first -> Data;
        if((iNo % 2) == 0)
        {
            iSum = iSum + iNo;
        }

        first = first -> Next;
    }

    return iSum;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 41);
    InsertFirst(&head, 32);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);

    Display(head);

    iRet = AdditionEven(head);

    printf("Addition of even numbers in the linked list is : %d", iRet);

    return 0;
}