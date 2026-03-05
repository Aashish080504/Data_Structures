import java.util.Scanner;

class BubbleSort
{
    public void sort(int Brr[])
    {
        int iValue = Brr.length;
        int i = 0, j = 0, temp = 0;

        for (i = 0; i < iValue - 1; i++)
        {
            for (j = 0; j < iValue - i - 1; j++)
            {
                if (Brr[j] > Brr[j + 1])
                {
                    temp = Brr[j];
                    Brr[j] = Brr[j + 1]; 
                    Brr[j + 1] = temp;
                }
            }
        }
    }
}

class BubbleSortDemo
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
        for (iCnt = 0; iCnt < iValue; iCnt++)
        {
            Arr[iCnt] = sobj.nextInt();
        }

        BubbleSort bobj = new BubbleSort();

        bobj.sort(Arr);

        System.out.print("Sorted array: ");
        for (iCnt = 0; iCnt < iValue; iCnt++)
        {
            System.out.print(Arr[iCnt] + " ");
        }

        sobj.close();
    }
}
