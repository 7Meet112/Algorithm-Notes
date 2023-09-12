/*
 * @FilePath: \VsCode\837\sort\MaoPao.cpp
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

void MaoPaoSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int nTemp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = nTemp;
            }
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
    MaoPaoSort(arr, 8);
    PrintArr(arr, 8);
    return 0;
}
