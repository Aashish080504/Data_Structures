/////////////////////////////////////////////////////////////////
//              Generalised Data Structure Library             
/////////////////////////////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------------
   Type                  Name of class for node              Name of class for Functionality
--------------------------------------------------------------------------------------------------
Singly Linear               SinglyLLLnode                          SinglyLLL          Done
Singly Circular             SinglyCLLnode                          SinglyCLL
Doubly Linear               DoublyLLLnode                          DoublyLLL          Done
Doubly Circular             DoublyCLLnode                          DoublyCLL
--------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
//              Singly Linear Linked List using Generic Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private :                     
        SinglyLLLnode<T> * first;
        int iCount;

    public :
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input    :          Data of node
//  Output    :         Nothing
//  Description   :     Used to insert node at first position
//  Author :            Sahil Rajaram Thorat
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no) 
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn -> next = this -> first;
    this -> first = newn;

    this -> iCount++;
}

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this -> iCount == 0)              
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;
}

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)        
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        this -> first = this -> first -> next;
        delete temp;
    }

    this -> iCount--;
}

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this -> first == NULL)
    {
        return;
    }
    else if(this -> first -> next == NULL)       
    {
        delete this -> first;
        this -> first = NULL;
    }
    else
    {
        temp = this -> first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this -> iCount--;
}

template<class T>
void SinglyLLL<T> :: Display()                 
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this -> first;

    cout << "\n";

    for(iCnt = 1; iCnt <= this -> iCount; iCnt++)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template<class T>
int SinglyLLL<T> :: Count()
{
    return this -> iCount;
}

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int Pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if (Pos < 1 || Pos > this -> iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(Pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if(Pos == this -> iCount + 1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this -> first;

        for(iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        this -> iCount++;
    }
}

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int Pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * target = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if (Pos < 1 || Pos > this -> iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(Pos == 1)
    {
        this -> DeleteFirst();
    }
    else if(Pos == this -> iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        this -> iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//              Doubly Linear Linked List using Generic Approch
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> * next;
        DoublyLLLnode<T> * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}
  
template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first -> prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;

    newn = new DoublyLLLnode<T>(no);

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
        newn -> prev = temp;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> * newn = NULL;
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                // LL is Empty
    {
        return;
    }
    else if(this->first -> next == NULL)  // LL contians one DoublyLLLnode
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  // LL contians more than one DoublyLLLnode  
    {
        this->first = this->first -> next;
        delete this->first -> prev;
        this->first -> prev = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                // LL is Empty
    {
        return;
    }
    else if(this->first -> next == NULL)  // LL contians one DoublyLLLnode
    {
        delete this->first;
        this->first = NULL;
    }
    else                                  // LL contians more than one DoublyLLLnode  
    {
        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this -> first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | <=> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////// End of Library ///////////////////////////////////////

int main()
{
    SinglyLLL<int> * obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertAtPos(75, 4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    delete obj;

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements of linked list are : "<<dobj->Count()<<"\n";

    delete dobj;

    return 0;
}