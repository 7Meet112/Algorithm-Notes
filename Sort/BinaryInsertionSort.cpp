
#include <stdio.h>

// 折半插入
void insertSort(int array[], int n)
{
    int temp;

    for (int i = 1; i < n; i++)
    {
        int low = 0;
        int hight = i - 1;
        temp = array[i];

        while (hight >= low)
        {
            int mid = (low + hight) / 2;
            if (array[mid] > temp)  hight = mid - 1;
            else    low = mid + 1;
        }

        for (int j = i - 1; j > hight; j--)
        {
            array[j + 1] = array[j];
        }

        array[hight + 1] = temp;
    }
}

void main()
{
    int i;
    int a[8] = {8, 5, 4, 3, 2, 1, 6, 7};

    printf("before:{");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    printf("}\n");

    insertSort(a, 8);

    printf("after:{");
    for (i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
    printf("}\n");
}
