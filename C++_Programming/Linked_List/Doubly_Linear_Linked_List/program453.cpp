// Doubly Linear LL

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
                this->first->next = NULL;
                this->first->previous = NULL;
            }

            else 
            {
                newn->next = this->first;
                this->first->previous = newn;
                this->first = newn;
            }

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
                this->first->next = NULL;
                this->first->previous = NULL;
            }

            else 
            {
                temp = this->first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
                newn->next = NULL;
            }

            this->iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            if((pos < 1) || (pos > iCount + 1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }

            else if(pos == iCount + 1)
            {
                this->InsertLast(no);
            }

            else 
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                
                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp =temp->next;
                }

                newn->next = temp->next;
                temp->next->previous = newn;
                temp->next = newn;
                newn->previous = temp;
                this->iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }

            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }

            else 
            {
                temp = this->first;

                this->first = this->first->next;
                this->first->previous = NULL;

                delete temp;
            }

            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }

            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }

            else 
            {
                temp = this->first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }

            this->iCount--;
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }

            else if(pos == iCount)
            {
                this->DeleteLast();
            }

            else 
            {                
                temp = this->first;

                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp =temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                target->next->previous = temp;
                delete target;
                this->iCount--;
            }
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;

            cout<<"\n NULL <=>";

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <=>";
                temp = temp->next;
            }

            cout<<"NULL\n ";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyLL obj;
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

    obj.InsertAtPos(75,2);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(2);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}