/*
 * @FilePath: \VsCode\837\sort\ChooseSort.cpp
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

void ChooseSort(int *arr, int size)
{
    int nMin = 0;
    for (int i = 0; i < size - 1; i++)
    {
        nMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[nMin])
            {
                nMin = j;
            }
        }

        if (nMin != i)
        {
            int nTemp = arr[nMin];
            arr[nMin] = arr[i];
            arr[i] = nTemp;
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


int main()
{
    int arr[] = {8, 5, 4, 3, 2, 1, 6, 7};
    PrintArr(arr, 8);
    ChooseSort(arr, 8);
    PrintArr(arr, 8);
    return 0;
}
