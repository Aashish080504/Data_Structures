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

bool CheckAllPositive(PNODE first)
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return 0; 
    }

    temp = first;

    while(temp != NULL)
    {
        if(temp -> data < 0)
        {
            return false;
        }

        temp = temp->next;
    }

    return true;
}

int main()
{
    int iRet = 0;
    bool bRet = false;
    PNODE head = NULL;

    InsertFirst(&head, 151);
    InsertFirst(&head, 121);
    InsertFirst(&head, 111);
    InsertFirst(&head, -51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    bRet = CheckAllPositive(head);
    
    if(bRet == true)
    {
        printf("All numbers are positive");
    }
    else
    {
       printf("All numbers are not positive"); 
    }

    return 0;
}
