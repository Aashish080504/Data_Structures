#include<iostream>
using namespace std;

#pragma pack(1)

class Queuenode
{
    public:
        int data;
        Queuenode * next;

        Queuenode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Queue
{
    private:
        Queuenode * first;
        int iCount;

    public:

        Queue()
        {
            cout<<"Queue gets created successfully...\n";

            this->first = NULL;
            this->iCount = 0;
        }

        void enqueue(int no)            
        {
            Queuenode * newn = NULL;
            Queuenode * temp = NULL;

            newn = new Queuenode(no);

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                temp = this->first;
                
                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
            }

            this->iCount++;
        }

        int dequeue()                
        {
            int Value = 0;
            Queuenode * temp = this->first;

            if(this->first == NULL)
            {
                cout<<"Queue is empty\n";
                return -1;
            }

            Value = this->first -> data;

            this->first = this->first -> next;
            delete temp;

            this->iCount--;

            return Value;
        }

        void Display()
        {
            Queuenode * temp = this->first;

            if(this->first == NULL)
            {
                cout<<"Queue is empty\n";
                return;
            }

            cout<<"\n";
            
            while (temp != NULL)
            {
                cout<<"| "<<temp->data<<" | -";
                temp = temp -> next;
            }

            cout<<"\n";
        }

        int Count()
        {
            return this->iCount;
        }
        
};

int main()
{
    Queue *qobj = new Queue();

    qobj->enqueue(11);
    qobj->enqueue(21);
    qobj->enqueue(51);
    qobj->enqueue(101);

    qobj->Display();
    cout<<"Number of elements in Queue : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of elements in Queue : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of elements in Queue : "<<qobj->Count()<<"\n";

    qobj->enqueue(121);

    qobj->Display();
    cout<<"Number of elements in Queue : "<<qobj->Count()<<"\n";

    delete qobj;
    
    return 0;
}