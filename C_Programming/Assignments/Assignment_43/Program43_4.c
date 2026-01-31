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

int SecMaximum(PNODE Head)
{
    int iMax1 = 0, iMax2 = 0;

    while(Head != NULL)
    {
        if(Head->Data > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = Head->Data;
        }
        else if((Head->Data > iMax2) && (Head->Data < iMax1))
        {
            iMax2 = Head->Data;
        }

        Head = Head->Next;
    }

    return iMax2;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 240);
    InsertFirst(&First, 320);
    InsertFirst(&First, 230);
    InsertFirst(&First, 110);

    Display(First);

    iRet = SecMaximum(First);

    printf("Second Maximum number from the linked list  is : %d\n", iRet);

    return 0;
}