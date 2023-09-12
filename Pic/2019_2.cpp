/*用二维数组存储,并用算法描述BFS*/

/*
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
The BFS traverse info :

E A B C
*/
#include <cstring> //memset()
#include "iostream"
#include "queue"

using namespace std;

#define Max 100
bool visited[Max];

typedef struct
{
    char v[Max];     //存放顶点
    int e[Max][Max]; //0 代表无连接 1 代表存在连接
    int n, m;        //当前矩阵的顶点和弧边数量
} MGraph;

queue<char> q; /* NOLINT */

int FindLocation(MGraph G, char x)
{
    for (int i = 0; i < G.n; ++i)
    {
        if (x == G.v[i])
            return i;
    }
    return -1;
}

void BFS(MGraph G)
{
    int i, j;
    memset(visited, false, sizeof visited); //初始化访问数组
    for (i = 0; i < G.n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cout << G.v[i] << " ";
            q.push(G.v[i]);
            //队不为空，队头元素出队访问它的下一个邻接点
            while (!q.empty())
            {
                //给当前i的值 置换为对头元素的下标
                i = FindLocation(G, q.front());
                q.pop();
                for (j = 0; j < G.n; ++j)
                {
                    //当遍历的两点之间存在边且未被访问过
                    if (G.e[i][j] == 1 && !visited[j])
                    {
                        visited[j] = true;
                        cout << G.v[j] << " ";
                        q.push(G.v[j]);
                    }
                }
            }
        }
    }
}

//使用邻接矩阵创建图 引用传值
void CreateAGraph(MGraph &G)
{
    puts("Please enter the vertex and edge:\n");
    cin >> G.n >> G.m;
    puts("Please enter the info about the vertex:\n");
    //the vertexes are put orderly,so the traversing is in oreder
    for (int i = 0; i < G.n; ++i)
    {
        cin >> G.v[i];
    }
    memset(G.e, 0, sizeof(G.e)); //初始化矩阵
    puts("Please enter a edge info from a vertex to another one by one in order:\n");
    //赋值 改变对应下标值
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
    puts("The BFS traverse info :\n");
    BFS(G);
    return 0;
}
