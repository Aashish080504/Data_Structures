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

void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))     // @
    {
        *first = newn;
        *last = newn;
    } 
    else
    {
        newn -> next = *first;
        *first = newn;
    }

    (*last) -> next = *first;                   // @
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
        (*last) -> next = *first;
    } 
    else
    {
        (*last) -> next = newn;                  // @
        *last = newn;                            // @
    }

    (*last) -> next = *first;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         // Case 1
    {
        return;
    }
    else if(*first == *last)                        // case 2
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else                                            // case 1
    {
        temp = *first;

        *first = (*first) -> next;
        free(temp);

        (*last) -> next = *first;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))         // Case 1
    {
        return;
    }
    else if(*first == *last)                        // case 2
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else                                            // case 1
    {
        temp = *first;

        while(temp -> next != *last)
        {
            temp = temp -> next;
        }

        free(*last);
        *last = temp;

        (*last) -> next = *first;
    }
}

void Display(PNODE first, PNODE last)
{
    printf(" \n-> ");
    do 
    {
        printf("| %d | -> ", first -> data);
        first = first -> next;
    }while(first != last -> next);

    printf("\n\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;
    
    do 
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int Pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    iSize = Count(*first, *last);

    if(Pos < 1 || Pos > iSize + 1)
    {
        printf("Invalid Position");
        return;
    }

    if(Pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(Pos == iSize + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int Pos)
{
    PNODE target = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;

    iSize = Count(*first, *last);

    if(Pos < 1 || Pos > iSize)
    {
        printf("Invalid Position");
        return;
    }

    if(Pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(Pos == iSize + 1)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < Pos -1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;          // @

    int iRet = 0;

    InsertFirst(&head, &tail, 51);
    InsertFirst(&head, &tail, 21);
    InsertFirst(&head, &tail, 11);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    InsertLast(&head, &tail, 101);
    InsertLast(&head, &tail, 111);
    InsertLast(&head, &tail, 121);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    InsertAtPos(&head, &tail, 75, 4);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteAtPos(&head, &tail, 4);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteFirst(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteLast(&head, &tail);

    Display(head, tail);
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    return 0;
}

/*

@ : Only this line is different compair to Singly linear linked list.

*/