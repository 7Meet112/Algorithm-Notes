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
 
A B D E C
*/

#include "iostream"
#include "stack"

#define Max 100

using namespace std;

bool visited[Max];

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

void DFS_NO_RC(GList &G,int v)
{
    stack<int>s;
    for (int i = 0; i < G.n; ++i) {
        visited[i] = false;
    }
    s.push(v),visited[v] = true;
    EdgeNode *p;
    while (!s.empty())
    {
        int k = s.top();
        cout << G.list[k].data << " ";
        s.pop();
        visited[k] = true;
        p = G.list[k].firstEdge;
        while (p)
        {
            int t = p->location;
            if (!visited[t]){
                s.push(t);
                visited[t] = true;
            }
            p = p->next;
        }
    }
}

int main()
{
    GList G;
    CreateGList(G);
    DFS_NO_RC(G,0);
    return 0;
}