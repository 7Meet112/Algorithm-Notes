```
#include <iostream>
using namespace std;

void ShellSort(int *arr, int size)
{
    int gap = size;
    while (gap > 1)
    {
        gap = gap / 3 + 1; // 调整希尔增量
        int i = 0;
        for (i = 0; i < size - gap; i++) // 从0遍历到size-gap-1
        {
            int end = i;
            int temp = arr[end + gap];
            // 插入排序
            while (end >= 0)
            {
                if (arr[end] > temp)
                {
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            arr[end + gap] = temp; // 以 end+gap 作为插入位置
        }
    }
}

void ShellSort1(int *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap = gap / 2)
    {
        // 遍历所有的元素
        for (int i = gap; i < size; i++)
        {
            // 遍历本组中所有元素
            for (int j = i - gap; j >= 0; j -= gap)
            {
                // 如果当前元素大于加上步长后的那个元素
                if (arr[j] > arr[j + gap])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + gap];
                    arr[j + gap] = temp;
                }
            }
        }
        // 打印每次排序后的结果
        // System.out.println(Arrays.toString(arr));
    }
}

int main()
{
    int arr[] = {8, 5, 4, 3, 2, 1, 6, 7};
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    std::cout << std::endl;
    ShellSort(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```
