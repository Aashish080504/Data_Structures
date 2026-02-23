#include<stdio.h>

void insertionSort(int Arr[], int No)
{
    int iCnt = 0, j = 0, key = 0;

    for(iCnt = 1; iCnt < No; iCnt++)
    {
        key = Arr[iCnt];
        j = iCnt - 1;

        while(j >= 0 && Arr[j] > key)
        {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }

        Arr[j + 1] = key;
    }
}

int main()
{
    int iValue = 0, iCnt = 0;
    int arr[iValue];

    printf("Enter the number of elements : ");
    scanf("%d", &iValue);

    printf("Enter %d elements : \n", iValue);
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        scanf("%d", &arr[iCnt]);
    }

    insertionSort(arr, iValue);

    printf("Sorted array : ");
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        printf("%d ", arr[iCnt]);
    }
    printf("\n");

    return 0;
}