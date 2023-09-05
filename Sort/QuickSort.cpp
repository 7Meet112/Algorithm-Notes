/*
 * @FilePath: \VsCode\837\sort\QuickSort.cpp
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

void PrintArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    std::cout << std::endl;
}

void quick_sort(int *num, int l, int r)
{
    // 如果小于等于1个数据元素·直接返回结束快排函数 r为数组元素总个数
    if (l + 1 >= r)
    {
        return;
    }

    int first = l, last = r - 1, key = num[first];
    while (first < last)
    {
        while (first < last && num[last] >= key)
        {
            --last;
        }
        // 如果值小于 key分界值 交换
        num[first] = num[last];
        while (first < last && num[first] < key)
        {
            ++first;
        }
        // 如果值大于key分界值 交换
        num[last] = num[first];
    }
    num[first] = key;
    // 递归左右部分进行快排
    quick_sort(num, l, first);
    quick_sort(num, first + 1, r);
}

void QuickSort(int array[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int i = left;
    int j = right;
    // 关键字取第一个s数：left
    while (i < j)
    {
        while (i < j && array[j] >= array[left])
        { // 从右往左寻找第一个小于关键字的数
            j--;
        }
        while (i < j && array[i] < array[left])
        { // 从左往右寻找第一个大于等于关键字的数
            i++;
        }
        int temp = array[i]; // 交换这两个数
        array[i] = array[j];
        array[j] = temp;
    } // 一份为二进行排序
    QuickSort(array, left, i - 1);
    QuickSort(array, i + 1, right);
}

void MyQuickSort(int *arr, int nLeft, int nRight)
{   
    if (nLeft >= nRight)
    {
        return;
    }

    int i = nLeft, j = nRight;
    while (i < j)
    {
        // 从右往左找第一个小于关键字
        while(i < j && arr[j] >= arr[nLeft]) j--;
        // 从左往右找第一个大于等于关键字
        while(i < j && arr[i] < arr[nLeft]) i++;

        // 交换
        int temp = arr[i]; // 交换这两个数
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // 递归执行左右数组
    MyQuickSort(arr, nLeft, i - 1);
    MyQuickSort(arr, i + 1, nRight);
}

int main()
{
    int arr[] = {8, 5, 4, 3, 2, 1, 6, 7, 90, 5, 4, 3, 2, 1};
    int nLen = sizeof(arr)/sizeof(int);
    PrintArr(arr, nLen);
    MyQuickSort(arr, 0, nLen - 1);
    PrintArr(arr, nLen);
    return 0;
}
