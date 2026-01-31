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

int LastOccur(PNODE first, int iNo)
{
    PNODE temp = first;
    int iPos = 1;
    int iLastPos = 0;

    while(temp != NULL)
    {
        if(temp->data == iNo)
        {
            iLastPos = iPos;
        }
        temp = temp->next;
        iPos++;
    }

    return iLastPos;
}

int main()
{
    int iRet = 0, iValue;
    PNODE head = NULL;

    InsertFirst(&head, 75);
    InsertFirst(&head, 11);
    InsertFirst(&head, 51);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("Enter the number to find : ");
    scanf("%d", &iValue);

    iRet = LastOccur(head, iValue);

    if(iRet == 0)
    {
        printf("The given number is not present in the linked list");
    }
    else
    {
        printf("Last occurence of %d is : %d\n",iValue, iRet);
    }

    return 0;
}
