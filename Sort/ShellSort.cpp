```
/*
 * @FilePath: \VsCode\C++\837\sort\ShellSort.cpp
 * @注释开始: ------------------------------------------------------------------------------
 * @版  权: (C) 深圳冰川网络技术有限公司 2008 - All Rights Reserved
 * @创建人: 刘建
 * @Date: 2023-09-04 15:02:07
 * @版  本: 1.0
 * @描  述:
 * @应  用:
 * @注释结束: ------------------------------------------------------------------------------
 */
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

void PrintArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    std::cout << std::endl;
}

void ShellSort1(int *arr, int size)
{
    for (int gap = size / 2; gap > 0; gap = gap / 2)
    {
        std::cout << gap << std::endl;
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
        PrintArr(arr, size);
    }
}

void ShellSort2(int *arr, int nSize)
{
    // gap
    for (int nGap = nSize / 2; nGap > 0; nGap /= 2)
    {
        // 全部组
        for (int i = nGap; i < nSize; i++)
        {
            // 每组
            for (int j = i - nGap; j >= 0; j-= nGap)
            {
                if (arr[j] > arr[j + nGap])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + gap];
                    arr[j + gap] = temp;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {8, 5, 4, 3, 2, 1, 6, 7};
    PrintArr(arr, 8);
    ShellSort1(arr, 8);
    PrintArr(arr, 8);
    return 0;
}
```
