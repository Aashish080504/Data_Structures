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
            cout<<"Object of SinglyLL gets created.\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {}

        void InsertLast(int no)
        {}

        void InsertAtPos(int no, int Pos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int Pos)
        {}

        void Display()
        {}

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

    return 0;
}