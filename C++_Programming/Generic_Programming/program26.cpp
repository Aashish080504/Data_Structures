////////////////////////////////////////////////////////////////////
// Final code of Queue using Generic Approch
///////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();
        void enqueue(T);             
        T dequeue();                 
        void Display();
        int Count(); 
};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created successfully...\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)            
{
    Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;                // newn
    }

    this->iCount++;
}

template<class T>
T Queue<T> :: dequeue()                
{
    int Value = 0;
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
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

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    cout<<"\n";
    
    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp -> next;
    }

    cout<<"\n";
}

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

int main()
{
    Queue<int> *qobj = new Queue<int>();

    int iChoice = 0;
    int Value = 0, iRet = 0;

    while(1)
    {
        cout<<"-------------------------------------------------------------------------\n";
        cout<<"------------------------Please Select the option-------------------------\n";
        cout<<"1 : Insert new element into the queue\n";
        cout<<"1 : Remove the element from the queue\n";
        cout<<"3 : Display the elements into the queue\n";
        cout<<"4 : count the number of elements from the queue\n";
        cout<<"0 : Exit the application\n";

        cout<<"-------------------------------------------------------------------------\n";
        cin>>iChoice;

        switch (iChoice)
        {
        case 1:
            cout<<"Enter the element that you want to insert : \n";
            cin>>Value;
            qobj->enqueue(Value);
            cout<<"Elements gets inserted successfully\n";
            break;
        
        case 2:
            iRet = qobj -> dequeue();

            if(iRet != -1)
            {
                cout<<"Element remove from queue is : "<<iRet<<"\n";
            }
            break;

        case 3:
            cout<<"Elements of the queue are : \n";
            qobj->Display();
            break;

        case 4:
            iRet = qobj->Count();
            cout<<"Number of elements in queue are : "<<iRet<<"\n";
            break;

        case 0:
            cout<<"Thank you for using our application\n";
            delete qobj;
            return 0;
        
        default:
            cout<<"Please enter the valid option\n";
        } // End of switch
    } // End of main

    return 0;
}