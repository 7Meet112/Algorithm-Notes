/*
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


The BFS traverse info :

A C B E D
The DFS traverse info :

A C E D B
*/

#include <iostream>
#include <cstring>
#include <queue>

#define Max 100

using namespace std;

bool visited[Max];
queue<char> qt; /* NOLINT */

//边表节点
struct EdgeNode
{
    int location; //邻接表头节点所指向的节点的定位序号，根据指向的序号定位到特定顶点
    struct EdgeNode *next;
};

//头节点 头节点的指针指向边表节点 当使用List作为使用该结构体的名称时，视其为一个数组
typedef struct VertexNode
{
    char data;
    EdgeNode *firstEdge;
} List;

typedef struct
{
    List list[Max]; //存储头节点的数组、索引
    int n, m;       //当前邻接表的顶点和边数
} GList;

void CreateGList(GList &G)
{
    EdgeNode *e;
    puts("Please enter the vertex and edge:\n");
    cin >> G.n >> G.m;
    //存放头节点 并初始化
    puts("Please enter the info about the vertex:\n");
    for (int i = 0; i < G.n; i++)
    {
        //every location locate different data only
        cin >> G.list[i].data;
        G.list[i].firstEdge = nullptr;
    }
    puts("Give the order from one to another using numbers:\n");
    //依次输入邻接表边的信息 from a to b
    int a, b;
    for (int j = 0; j < G.m; ++j)
    {
        cin >> a >> b;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->location = a;
        e->next = G.list[b].firstEdge; //指向当前顶点指向的节点
        G.list[b].firstEdge = e;
        //无向图 没有方向
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->location = b;
        e->next = G.list[a].firstEdge;
        G.list[a].firstEdge = e;
    }
}

int FindLocation(GList G, char x)
{
    for (int i = 0; i < G.n; ++i)
        if (G.list[i].data == x)
            return i;
    return -1;
}

//使用邻接表BFS 相对矩阵复杂
void BFS(GList G, int i)
{
    EdgeNode *q;
    visited[i] = true;
    //打印顶点
    cout << G.list[i].data << " ";
    // 进队
    qt.push(G.list[i].data);
    while (!qt.empty())
    {
        int locate = FindLocation(G, qt.front());
        qt.pop();
        //当前顶点有临边时 注意不能使用 i 而是使用 locate
        q = G.list[locate].firstEdge;
        while (q)
        {
            //未访问过
            if (!visited[q->location])
            {
                visited[q->location] = true;
                cout << G.list[q->location].data << " ";
                qt.push(G.list[q->location].data); //入队
            }
            q = q->next; //当该顶点无临边时，下一次访问需定位到新的头节点上去，即 G.list[q->location].data
        }
    }
}

void BFSTraverse(GList G)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < G.n; i++)
        if (!visited[i])
            BFS(G, i);
}

void DFS(GList G, int i)
{
    EdgeNode *p;
    visited[i] = true;
    cout << G.list[i].data << " "; //从当前顶点开始
    p = G.list[i].firstEdge;
    //只要其为非空，就开始遍历整个邻接表
    while (p)
    {
        if (!visited[p->location])
        {
            DFS(G, p->location);
        }
        p =G.list[p->location].firstEdge;
    }
}

void DFSTraverse(GList G)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < G.n; ++i)
        if (!visited[i])
            DFS(G, i);
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
    puts("\nThe BFS traverse info :\n");
    BFSTraverse(G);
    puts("\nThe DFS traverse info :\n");
    DFSTraverse(G);
    return 0;
}