```
/*编写程序，关于链表的操作，对于一个已知的链表，选出链表中的最小值，并输出；    */

#include <iostream>
using namespace std;

typedef struct LNode // 使用List的话需要加typedef
{
    int data;
    struct LNode* next;
}*List;

List InsertList(List& L, int length)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
    List temp = L;
    int num = 0;
    for (int i = 0; i < length; i++)
    {
        List s = (LNode*)malloc(sizeof(LNode));
        cin >> num;
        s->data = num;
        s->next = temp->next;
        temp->next = s;
    }
    return L;
}

int Find_Min(List L)
{
    int res = L->next->data;// 初始化最小值为第一个节点的值，防止部分编译器不初始化值
    while (L->next != nullptr)
    {
        res = min(res, L->next->data);
        L = L->next;
    }
    return res;
}
int main()
{
    List L;
    int length = 0;
    puts("\nPlease enter the length of the list!\n");
    cin >> length;
    puts("\nPlease give values in order!\n");
    InsertList(L, length);
    puts("\nThe smallest value is :  \n");
    cout << Find_Min(L) << endl;
    return 0;
}



```
