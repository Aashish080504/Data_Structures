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
        
        bool CheckSorted();
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

    // Sorted = CheckSorted();
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

// 0    1   2   3   4   5   6   7   8   9
// 12   14  17  24  28  36  48  52  52  65
bool ArrayX :: CheckSorted()
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

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();
    aobj.Display();

    if(aobj.Sorted == true)
    {
        cout << "Data is sorted.\n";
    }
    else
    {
        cout << "Data is not sorted.\n";
    }

    return 0;
}
