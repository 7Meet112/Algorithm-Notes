#### 邻接矩阵
```
/*
邻接矩阵(无向图)
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

using namespace std;

#define Max 100

typedef struct
{
    char v[Max];     // 存放顶点
    int e[Max][Max]; // 0代表无连接 1 代表存在连接
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
#### 邻接表
```
/*
邻接表
Please enter the vertex and edge:
5 6
Please enter the info about the vertex:
A B C D E
Give the order from one to another using numbers:
0 1
2 0
1 3
1 4
3 4
2 4
The Glist info;
A:-> C B
B:-> E D A
C:-> E A
D:-> E B
E:-> C D B
*/
#include <iostream>
#include <cstring>
#define Max 100
using namespace std;
// 边表节点
struct EdgeNode
{
    int location; // 邻接表头节点所指向的节点的定位序号，根据指向的序号定位到特定顶点
    struct EdgeNode *next;
};

// 头节点 头节点的指针指向边表节点 当使用List作为使用该结构体的名称时，视其为一个数组
typedef struct VertexNode
{
    char data;
    EdgeNode *firstEdge;
} List;

typedef struct
{
    List list[Max]; // 存储头节点的数组、索引
    int n, m;       // 当前邻接表的顶点和边数
} GList;

void CreateGList(GList &G)
{
    EdgeNode *e;
    puts("Please enter the vertex and edge:\n");
    cin >> G.n >> G.m;
    // 存放头节点 并初始化
    puts("Please enter the info about the vertex:\n");
    for (int i = 0; i < G.n; i++)
    {
        // every location locate different data only
        cin >> G.list[i].data;
        G.list[i].firstEdge = nullptr;
    }
    puts("Give the order from one to another using numbers:\n");
    // 依次输入邻接表边的信息 from a to b
    int a, b;
    for (int j = 0; j < G.m; ++j)
    {
        cin >> a >> b;
        // 头插，最后一个指向nullptr
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->location = a;
        e->next = G.list[b].firstEdge; // 指向当前顶点指向的节点
        G.list[b].firstEdge = e;

        // 无向图 没有方向
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->location = b;
        e->next = G.list[a].firstEdge;
        G.list[a].firstEdge = e;
    }
}

void ShowGList(GList G)
{
    EdgeNode *e;
    for (int i = 0; i < G.n; ++i)
    {
        cout << G.list[i].data << ":-> ";
        e = G.list[i].firstEdge;
        while (e)
        {
            cout << G.list[e->location].data << " ";
            e = e->next;
        }
        puts("\n");
    }
}

int main()
{
    GList G;
    CreateGList(G);
    puts("\nThe Glist info;\n");
    ShowGList(G);
    return 0;
}
```
