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

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Next = NULL;
    newn -> Data = No;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> Next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d |->", Head -> Data);
        Head = Head -> Next;
    }
    
    printf("NULL\n");
}

int SearchLastOcc(PNODE Head, int iNo)
{
    int iPos = 0;
    int iLast = 0;

    iPos = 1;
    while(Head != NULL)
    {
        if(Head->Data == iNo)
        {
            iLast = iPos;   
        }
        iPos++;
        Head = Head->Next;
    }

    return iLast;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 70);
    InsertFirst(&First, 30);
    InsertFirst(&First, 50);
    InsertFirst(&First, 40);
    InsertFirst(&First, 30);
    InsertFirst(&First, 20);
    InsertFirst(&First, 10);

    Display(First);

    iRet = SearchLastOcc(First, 30);

    printf("Last occurence is : %d\n", iRet);

    return 0;
}