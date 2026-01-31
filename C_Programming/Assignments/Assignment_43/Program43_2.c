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

void DisplayPrime(PNODE first)
{
    int iCnt = 0, iCount = 0, iNo = 0;

    printf("Prime numbers are : ");

      while(first != NULL)
    {
        iNo = first->Data;
        iCount = 0;

        for(iCnt = 1; iCnt <= iNo; iCnt++)
        {
            if(iNo % iCnt == 0)
            {
                iCount++;
            }
        }

        if(iCount == 2)
        {
            printf("%d\t", iNo);
        }

        first = first->Next;
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head, 89);
    InsertFirst(&head, 22);
    InsertFirst(&head, 41);
    InsertFirst(&head, 17);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);

    Display(head);

    DisplayPrime(head);

    return 0;
}