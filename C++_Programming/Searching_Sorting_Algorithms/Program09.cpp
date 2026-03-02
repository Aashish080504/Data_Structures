#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        ArrayX(int no);
        ~ArrayX();

        void Accept();
        void Display();

        bool LinearSearch(int iNo);
        bool BiDirectionalSearch(int iNo);
        bool BinarySearch(int iNo);

        bool checkSorted();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()            // Time Complexity N. It will sort while getting the input
{  
    int iCnt = 0;

    cout<<"Enter the elements : \n";

    cin >> Arr[iCnt];               // Get first input outside the loop

    for(iCnt = 1; iCnt < iSize; iCnt++) // Start loop from 1st index
    {
        cin >> Arr[iCnt];

        if(Arr[iCnt - 1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

    // Sorted = checkSorted();
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

// 0    1   2   3   4   5   6   7   8   9
// 12   14  17  24  28  36  48  52  52  65
bool ArrayX :: checkSorted()
{
    int i = 0;
    bool bFlag = true;

    for (i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

bool ArrayX :: BinarySearch(int iNo)           // Updated
{
    int iStart = 0, iMid = 0, iEnd = 0;
    bool bFlag = false;

    if(Sorted == false)                        // If not sorted then return false.
    {
        return false;
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid + 1;
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
/*
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


    if(aobj.Sorted == true)
    {
        cout << "Data is sorted.\n";
    }
    else
    {
        cout << "Data is not sorted.\n";
    }

 */

    if(aobj.BinarySearch(21))
    {
        cout << "Element is Present. \n";
    }
    else
    {
        cout << "There is no such element\n";
    }

    return 0;
}
