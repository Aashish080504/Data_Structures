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

void MultiplyByTwo(PNODE first)
{
    PNODE temp = NULL;
    int iNo = 0;

    temp = first;

    while(temp != NULL)
    {
        iNo = temp -> data;

        iNo = iNo * 2;

        printf("| %d | -> ", iNo);
        temp = temp -> next;
    }
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head, 121);
    InsertFirst(&head, 111);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    printf("Linked list after Multiply each element by 2 is : \n");
    MultiplyByTwo(head);

    return 0;
}
