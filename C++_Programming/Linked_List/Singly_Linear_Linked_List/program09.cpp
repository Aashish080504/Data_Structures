#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    public :
        PNODE first;
        int iCount;

        SinglyLL()
        {
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)   // Updated
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            newn -> next = first;
            first = newn;
    
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            if(iCount == 0)               // Updated
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
            }

            iCount++;
        }

        void InsertAtPos(int no, int Pos)
        {}

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)        // else if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                first = first -> next;
                delete temp;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)        // else if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }

                delete temp -> next;
                temp -> next = NULL;
            }

            iCount--;
        }

        void DeleteAtPos(int Pos)
        {}

        void Display()                 // Updated
        {
            PNODE temp = NULL;
            int iCnt = 0;

            temp = first;

            cout << "\n";

            for(iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout << "| " << temp->data << " | -> ";
                temp = temp->next;
            }

            cout << "NULL\n\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}