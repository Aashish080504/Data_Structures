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

void SumDigits(PNODE first)
{
    int iCnt = 0, iSum = 0, iNo = 0, iDigit = 0;

    printf("Summation of digits from the linked list are : ");

      while(first != NULL)
    {
        iNo = first->Data;
        iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }

        printf("%d\t", iSum);

        first = first->Next;    
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 640);
    InsertFirst(&head, 640);
    InsertFirst(&head, 20);
    InsertFirst(&head, 230);
    InsertFirst(&head, 110);

    Display(head);

    SumDigits(head);

    return 0;
}