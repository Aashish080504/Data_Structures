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

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
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

void DisplayGreaterThanAvg(PNODE first)
{
    PNODE temp = NULL;
    int iSum = 0, iAvg = 0, iCount = 0;

    if(first == NULL)
    {
        return;
    }

    temp = first;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        iCount++;
        temp = temp->next;
    }

    iAvg = iSum / iCount;

    printf("Elements greater than average %d are:\n", iAvg);

    temp = first;

    while(temp != NULL)
    {
        if(temp->data > iAvg)
        {
            printf("| %d | -> ", temp->data);
        }
        temp = temp->next;
    }

    printf("NULL\n");
}


int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head, 151);
    InsertFirst(&head, 120);
    InsertFirst(&head, 111);
    InsertFirst(&head, 50);
    InsertFirst(&head, 20);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    DisplayGreaterThanAvg(head);

    return 0;
}
