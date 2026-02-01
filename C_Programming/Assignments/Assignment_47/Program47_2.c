#include<stdio.h>
#include<stdlib.h>

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

void CountDigits(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0, iNo = 0;

    temp = first;

    while(temp != NULL)
    {
        iCount = 0;
        iNo = 0;

        iNo = temp -> data;

        while(iNo > 0)
        {
            iCount++;
            iNo = iNo / 10;
        }
        
        printf("| %d | -> ", iCount);
        temp = temp->next;
    }
}

int main()
{
    int iRet = 0, iValue = 0;
    PNODE head = NULL;

    InsertFirst(&head, 725);
    InsertFirst(&head, 11);
    InsertFirst(&head, 5211);
    InsertFirst(&head, 22);
    InsertFirst(&head, 1);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("Number of Digits in each node are : \n");
    CountDigits(head);

    return 0;
}
