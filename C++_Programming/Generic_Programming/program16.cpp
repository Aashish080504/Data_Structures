#include<iostream>
using namespace std;

#pragma pack(1)

class Stacknode
{
    public:
        int data;
        Stacknode * next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        Stacknode * first;
        int iCount;

    public:
        Stack();
        void Push(int);            // InsertFirst
        int Pop();                 // DeleteFirst
        int peep();
        void Display();
        int Count(); 
};

Stack :: Stack()
{}

void Stack :: Push(int no)            
{}

int Stack :: Pop()                
{
    return 0;
}

int Stack :: peep()
{
    return 0;
}

void Stack :: Display()
{}

int Stack :: Count()
{
    return this->iCount;
}

int main()
{
    Stack *sobj = new Stack();

    delete sobj;
    
    return 0;
}