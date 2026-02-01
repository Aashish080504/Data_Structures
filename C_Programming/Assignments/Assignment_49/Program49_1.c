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

int Difference(PNODE first)
{
    PNODE temp = NULL;
    int iMax = 0, iMin = 0;

    if(first == NULL)
    {
        return 0;
    }

    temp = first;
    iMax = temp -> data;
    iMin = temp -> data;

    while(temp != NULL)
    {
        if(temp -> data > iMax)
        {
            iMax = temp -> data;
        }
        
        if(temp -> data < iMin)
        {
            iMin = temp -> data;
        }

        temp = temp->next;
    }

    return iMax - iMin;
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head, 151);
    InsertFirst(&head, 121);
    InsertFirst(&head, 11);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 111);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    iRet = Difference(head);
    printf("Difference between Maximum and Minimum is : %d\n", iRet);

    return 0;
}
