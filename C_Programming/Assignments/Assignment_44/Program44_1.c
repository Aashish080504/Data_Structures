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

bool Search(PNODE first, int iNo)
{
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        if(temp -> data == iNo)
        {
            return true;
        }

        temp = temp -> next;
    }

    return false;
}

int main()
{
    int iRet = 0, iValue;
    bool bRet = false;
    PNODE head = NULL;

    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("Enter number to search : ");
    scanf("%d", &iValue);

    bRet = Search(head, iValue);

    if(bRet == true)
    {
        printf("Number is present in linked list.\n");
    }
    else
    {
        printf("Number is not present in linked list.\n");
    }

    return 0;
}
