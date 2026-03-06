import java.util.Scanner;

class InsertionSort
{
    public void sort(int Brr[])
    {
        int i = 0, j = 0, key = 0;
        int iValue = Brr.length;

        for (i = 1; i < iValue; i++)
        {
            key = Brr[i];
            j = i- 1;

            while (j >= 0 && Brr[j] > key)
            {
                Brr[j + 1] = Brr[j];
                j--;
            }

            Brr[j + 1] = key;
        }
    }
}

class InsertionSortDemo
{
    public static void main(String[] args)
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;
        int iCnt = 0;

        System.out.print("Enter number of elements: ");
        iValue = sobj.nextInt();

        int Arr[] = new int[iValue];

        System.out.println("Enter " + iValue + " elements:");
        for(iCnt = 0; iCnt < iValue; iCnt++)
        {
            Arr[iCnt] = sobj.nextInt();
        }

        InsertionSort iobj = new InsertionSort();

        iobj.sort(Arr);

        System.out.print("Sorted array: ");
        for (iCnt = 0; iCnt < iValue; iCnt++)
        {
            System.out.print(Arr[iCnt] + " ");
        }

        sobj.close();
    }
}
