#### 邻接矩阵
```
/*
邻接矩阵
Please enter the vertex and edge:

4 5

Please enter the info about the vertex:

E A C B

Please enter a edge info from a vertex to another one by one in order:

A E
A B
A C
B E
B C
*/
#include "cstring" //memset()
#include "iostream"
#include "queue"

using namespace std;

#define Max 100

typedef struct
{
    char v[Max];     // 存放顶点
    int e[Max][Max]; // 0 代表无连接 1 代表存在连接
    int n, m;        // 当前矩阵的顶点和弧边数量
} MGraph;

int FindLocation(MGraph G, char x)
{
    for (int i = 0; i < G.n; ++i)
    {
        if (x == G.v[i])
            return i;
    }
    return -1;
}

// 使用邻接矩阵创建图 引用传值
void CreateAGraph(MGraph &G)
{
    puts("\nPlease enter the vertex and edge:\n");
    cin >> G.n >> G.m;
    puts("\nPlease enter the info about the vertex:\n");
    // the vertexes are put orderly,so the traversing is in oreder
    for (int i = 0; i < G.n; ++i)
    {
        cin >> G.v[i];
    }
    memset(G.e, 0, sizeof(G.e)); // 初始化矩阵
    puts("\nPlease enter a edge info from a vertex to another one by one in order:\n");
    // 赋值 改变对应下标值
    char s1, s2;
    for (int i = 0; i < G.m; ++i)
    {
        cin >> s1 >> s2;
        G.e[FindLocation(G, s1)][FindLocation(G, s2)] = G.e[FindLocation(G, s2)][FindLocation(G, s1)] = 1;
    }
}
int main()
{
    MGraph G;
    CreateAGraph(G);
    return 0;
}
```
