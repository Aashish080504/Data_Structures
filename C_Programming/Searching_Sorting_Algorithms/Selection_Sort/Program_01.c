#include<stdio.h>

void SelectionSort(int Arr[], int No)
{
    int iMinIndex = 0;
    int x = 0, y = 0, temp = 0;

    for(x = 0; x < No; x++)
    {
        iMinIndex = x;
        for(int y = x; y < No; y++)
        {
            if(Arr[iMinIndex] > Arr[y])
            {
                iMinIndex = y;
            }
        }

        temp = Arr[x];
        Arr[x] = Arr[iMinIndex];
        Arr[iMinIndex] = temp;
    }
}

int main()
{
    int iValue = 0, iCnt = 0;
    int arr[iValue];

    printf("Enter number of elements: ");
    scanf("%d", &iValue);

    printf("Enter %d elements: \n", iValue);
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        scanf("%d", &arr[iCnt]);
    }

    SelectionSort(arr, iValue);

    printf("Sorted Array is : ");
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        printf("%d ", arr[iCnt]);
    }
    printf("\n");

    return 0;
}