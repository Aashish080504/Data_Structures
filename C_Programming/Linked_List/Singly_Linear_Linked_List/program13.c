#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call by value

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\t", first -> data);
        first = first -> next;
    }
    printf("\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

// Call by Address

void InsertFirst(PPNODE first, int no)
{}

void InsertLast(PPNODE first, int no)
{}

void InsertAtPos(PPNODE first, int no, int pos)
{}

void DeleteFirst(PPNODE first)
{}

void DeletetLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int pos)
{}

int main()
{
    PNODE head = NULL;

    Display(head);
    Count(head);

    InsertFirst(&head, 11);
    InsertLast(&head, 21);
    InsertAtPos(&head, 51, 5);

    DeleteFirst(&head);
    DeletetLast(&head);
    DeleteAtPos(&head, 5);

    return 0;
}


