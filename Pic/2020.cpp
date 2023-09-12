/*设计算法将无向图邻接表转换为邻接矩阵*/

/*算法思想：
1.给定无向图邻接表，对每一个头节点遍历邻边
2.对于遍历的邻边，使用邻接矩阵保存即可
*/

/*
Please enter the vertex and edge:

5 6

Please enter the info about the vertex:

A B C D E 

Give the order from one to another using numbers:

0 1
0 2
1 3
3 4
1 4
2 4

The info of the MGraph:

A B C D E 
*/
#include "cstring" //memset()
#include "iostream"

using namespace std;

#define Max 100

//邻接矩阵
typedef struct
{
    char v[Max];     //存放顶点
    int e[Max][Max]; //0 代表无连接 1 代表存在连接
    int n, m;        //当前矩阵的顶点和弧边数量
} MGraph;

//邻接表
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

//使用邻接表创建图
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

//遍历图
void Exchange(GList G, MGraph &MG)
{

    //初始化MG
    MG.n = G.n;
    MG.m = G.m;
    memset(MG.e, 0, sizeof(MG.e));
    EdgeNode *e;
    for (int i = 0; i < G.n; ++i)
    {
        //读入头节点到矩阵中
        MG.v[i] = G.list[i].data;
        //开始遍历
        e = G.list[i].firstEdge;
        while (e)
        {
            //说明G.list[i].data与G.list[e.location].data存在节点
            MG.e[i][e->location] = MG.e[e->location][i] = 1;
            e = e->next;
        }
    }
}

void Display(MGraph MG)
{
    puts("The info of the MGraph:\n");
    for (int i = 0; i < MG.n; ++i)
    {
        cout << MG.v[i] << " ";
    }
}

int main()
{
    GList G;
    MGraph MG;
    CreateGList(G);
    Exchange(G, MG);
    Display(MG);
    return 0;
}