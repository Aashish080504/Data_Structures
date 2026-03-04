#include<iostream>
using namespace std;

# define INC_ORDER 1
# define DEC_ORDER 2

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
        void BubbleSortEfficient();
        void BubbleSortEfficientX(int iOption);

        void SelectionSort();
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

void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;
    int Pass = 0;
    int Time = 0;

    if(Sorted == true)                          // Important filter
    {
        return;
    }

    Time = 1;

    for (i = 0, Pass = 1; i < iSize - 1; i++, Pass++)             // Outer loop
    {
        for (j = 0; j < iSize - 1 -i; j++, Time++)     // Inner Loop
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

    cout << "Number of passes for BubbleSort : " << Pass << "\n";

    cout << "Total Number of iterations : " << Time << "\n";

    Sorted = true;
}

/*
    Pass 1 : 0  1   2   3
    Pass 2 : 0  1   2
    Pass 3 : 0  1
    Pass 4 : 0
*/

// 21   15  18  16  11
void ArrayX :: BubbleSortEfficient()
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

/*

    if(Sorted == true)                          // Important filter
    {
        return;
    }

*/

    bFlag = true;

    for (i = 0; (i < iSize - 1) && (bFlag == true); i++)             // Outer loop
    {
        bFlag = false;

        for (j = 0; j < iSize - 1 -i; j++)     // Inner Loop
        {
            if(Arr[j] > Arr[j + 1])                     
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout << "\nData After pass :- " << i + 1 << "\n";
        Display();
    }

    cout << "Number of passes for BubbleSortEfficient : " << i << "\n";

    Sorted = true;
}

// 1  : Increasing
// 2  : Decreasing
void ArrayX :: BubbleSortEfficientX(int iOption = INC_ORDER)
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;


    if(iOption < INC_ORDER || iOption > DEC_ORDER)             // 1  || 2
    {
        cout << "Invalid option for Sorting\n";
        cout << "1  : Increasing\n";
        cout << "2  : Decreasing\n";
    }

/*

    if(Sorted == true)                          // Important filter
    {
        return;
    }

*/

    bFlag = true;

    if(iOption == INC_ORDER)
    {
        for (i = 0; (i < iSize - 1) && (bFlag == true); i++)             // Outer loop
        {
            bFlag = false;

            for (j = 0; j < iSize - 1 -i; j++)     // Inner Loop
            {
                if(Arr[j] > Arr[j + 1])                     
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }

            cout << "\nData After pass :- " << i + 1 << "\n";
            Display();
        }
    } // End of if(iOption == 1)

    else if(iOption == DEC_ORDER)
    {
        for (i = 0; (i < iSize - 1) && (bFlag == true); i++)             // Outer loop
        {
            bFlag = false;

            for (j = 0; j < iSize - 1 -i; j++)     // Inner Loop
            {
                if(Arr[j] < Arr[j + 1])                     
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }

            cout << "\nData After pass :- " << i + 1 << "\n";
            Display();
        }
    } // End of else if(iOption == 2)

    cout << "Number of passes for BubbleSortEfficient : " << i << "\n";

    Sorted = true;
}

/*
    Pass 1 : 0  1   2   3
    Pass 2 : 0  1   2
    Pass 3 : 0  1
    Pass 4 : 0
*/

void ArrayX :: SelectionSort()
{
    int i = 0, j = 0, temp = 0;
    int min_index = 0;

    for (i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
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

    // 1  : Increasing
    // 2  : Decreasing
    // aobj.BubbleSortEfficientX(DEC_ORDER);

    aobj.SelectionSort();
    
    cout << "\nData After Sorting :-\n";
    aobj.Display();

    return 0;
}

