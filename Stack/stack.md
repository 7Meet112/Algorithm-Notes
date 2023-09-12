```
#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;
enum Status
{
    OK = 0,
    ERROR,
};

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
    S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
    if(S.base == S.top) return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if (!S.base) return ERROR;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }

    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

Status GetSize(SqStack S, SElemType &e)
{
    e = S.top - S.base;
    return OK;
}

bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return true;
    else 
        return false;
}

// 数制转换（10 -> 8）
void Test1()
{
    SqStack S;
    InitStack(S);

    int N = 0;
    cin >> N;
    while (N)
    {
        Push(S, N % 8);
        N /= 8;
    }

    SElemType e;
    while (!StackEmpty(S))
    {
        Pop(S,e);
        std::cout << e << " ";
    }
}

// 迷宫
/*
typedef struct
{
    int ord;
    PosType seat;
    in di;
}SElemType;
*/
void Test2()
{

}

// hanoi
void test3(int n, char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z);
    else
    {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y ,x, z);
    }
}

int main()
{
    SqStack S;
    SElemType e = 0;
    std::cout << InitStack(S) <<std::endl;
    std::cout << Push(S, 100) <<std::endl;
    std::cout << GetTop(S, e) <<std::endl;
    std::cout << e <<std::endl;
    std::cout << Pop(S, e) <<std::endl;
    std::cout << e <<std::endl;
    std::cout << GetSize(S, e) <<std::endl;
    std::cout << e <<std::endl;

    Test1();
    
    return 0;
}

```
