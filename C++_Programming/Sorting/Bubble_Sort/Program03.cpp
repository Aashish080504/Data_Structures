#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        // Constructor, Destructor
        ArrayX(int no);
        ~ArrayX();

        // Accept the values and Display the values
        void Accept();
        void Display();

        bool CheckSorted();

        void BubbleSort();
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

// 21   15  18  16  11
void ArrayX :: BubbleSort()
{
    int i = 0, j = 0, temp = 0;

    if(Sorted == true)                          // Important filter
    {
        return;
    }

    for (i = 0; i < iSize - 1; i++)             // Outer loop
    {
        for (j = 0; j < iSize - 1 - i; j++)     // Inner Loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout << "\nData After pass :- " << i + 1 << "\n";
        Display();
    }

    Sorted = true;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    cout << "\nData Before Sorting :-\n";
    aobj.Display();

    if(aobj.Sorted == true)
    {
        cout << "\nData is sorted.\n";
    }
    else
    {
        cout << "\nData is not sorted.\n";
    }

    aobj.BubbleSort();

    cout << "\nData After Sorting :-\n";
    aobj.Display();

    return 0;
}

/*

    Enter the number of elements : 
    5
    Inside constructor
    Enter the elements : 
    21
    15
    18
    16
    11

    Data Before Sorting :-
    Elemets of the array are : 
    21      15      18      16      11

    Data is not sorted.

    Data After pass :- 1
    Elemets of the array are : 
    15      18      16      11      21

    Data After pass :- 2
    Elemets of the array are :
    15      16      11      18      21

    Data After pass :- 3
    Elemets of the array are :
    15      11      16      18      21

    Data After pass :- 4
    Elemets of the array are :
    11      15      16      18      21

    Data After Sorting :-
    Elemets of the array are :
    11      15      16      18      21

*/
