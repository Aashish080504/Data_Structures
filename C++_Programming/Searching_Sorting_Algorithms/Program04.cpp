#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no);
        ~ArrayX();

        void Accept();
        void Display();
        
        bool LinearSearch(int iNo);
        bool BiDirectionalSearch(int iNo);
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

void ArrayX :: Display()
{
    int iCnt = 0;

    cout<<"Elemets of the array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }

    cout<<"\n";
}

bool ArrayX :: LinearSearch(int iNo)
{
    bool bFlag = false;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            bFlag = true;
            break;
        }
    }
    
    return bFlag;
}

bool ArrayX :: BiDirectionalSearch(int iNo)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd  = 0;

    for(iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
    }
    
    return bFlag;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();
    aobj.Display();

    if(aobj.LinearSearch(21))
    {
        cout << "Element is present.\n";
    }
    else
    {
        cout << "Element is Not present.\n";
    }

    if(aobj.BiDirectionalSearch(21))
    {
        cout << "Element is present.\n";
    }
    else
    {
        cout << "Element is Not present.\n";
    }
    
    return 0;
}
