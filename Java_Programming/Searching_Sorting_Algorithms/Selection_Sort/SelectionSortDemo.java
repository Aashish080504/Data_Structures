import java.util.Scanner;

class SelectionSort
{
    public void sort(int[] Brr)
    {
        int index_of_min = 0;
        int i = 0, j = 0, temp = 0, iValue = 0;

        iValue = Brr.length;

        for (i = 0; i < iValue - 1; i++)
        {
            index_of_min = i;

            for (j = i + 1; j < iValue; j++)
            {
                if (Brr[j] < Brr[index_of_min])
                {
                    index_of_min = j;
                }
            }

            temp = Brr[i];
            Brr[i] = Brr[index_of_min];
            Brr[index_of_min] = temp;
        }
    }
}

class SelectionSortDemo
{
    public static void main(String[] args)
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;
        int iCnt = 0;

        System.out.print("Enter number of elements: ");
        iValue = sobj.nextInt();

        int[] Arr = new int[iValue];

        System.out.println("Enter " + iValue + " elements:");
        for(iCnt = 0; iCnt < iValue; iCnt++)
        {
            Arr[iCnt] = sobj.nextInt();
        }

        SelectionSort ssobj = new SelectionSort();

        ssobj.sort(Arr);

        System.out.print("Sorted array: ");
        for(iCnt = 0; iCnt < iValue; iCnt++)
        {
            System.out.print(Arr[iCnt] + " ");
        }

        sobj.close();
    }
}
