#include<stdio.h>

void BubbleSort(int Arr[], int No)
{
    int iCnt = 0, j = 0, temp = 0;

    for(iCnt = 0; iCnt < No; iCnt++)
    {
        for(j = 0; j < No - iCnt - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int iValue = 0, iCnt = 0;
    int arr[iValue];

    printf("Enter number of elements : ");
    scanf("%d", &iValue);

    printf("Enter %d elements : \n", iValue);
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        scanf("%d", &arr[iCnt]);
    }

    BubbleSort(arr, iValue);

    printf("Sorted array : ");
    for(iCnt = 0; iCnt < iValue; iCnt++)
    {
        printf("%d ", arr[iCnt]);
    }
    printf("\n");

    return 0;
}