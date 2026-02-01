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

bool CheckSorted(PNODE first)
{
    PNODE temp = first;

    if(first == NULL || first->next == NULL)
    {
        return true;
    }

    while(temp->next != NULL)
    {
        if(temp->data > temp->next->data)
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
    InsertFirst(&head, 120);
    InsertFirst(&head, 111);
    InsertFirst(&head, 50);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n\n", iRet);

    bRet = CheckSorted(head);
    
    if(bRet == true)
    {
        printf("Linked list is sorted in ascending order\n");
    }
    else
    {
        printf("Linked list is NOT sorted in ascending order\n");
    }

    return 0;
}
