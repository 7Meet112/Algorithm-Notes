
```
// prim 算法求最小生成树

// https://blog.csdn.net/qq_62213124/article/details/121597780?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169405147216800222837991%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169405147216800222837991&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-4-121597780-null-null.142^v93^chatgptT3_2&utm_term=%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91&spm=1018.2226.3001.4187

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 505;

int a[maxn][maxn];

int vis[maxn], dist[maxn];

int n, m;

int u, v, w;

long long sum = 0;

int prim(int pos)
{
    dist[pos] = 0;
    // 一共有 n 个点,就需要 遍历 n 次,每次寻找一个权值最小的点,记录其下标
    for (int i = 1; i <= n; i++)
    {
        int cur = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (cur == -1 || dist[j] < dist[cur]))
            {
                cur = j;
            }
        }
        // 这里需要提前终止
        if (dist[cur] >= INF)
            return INF;
        sum += dist[cur];
        vis[cur] = 1;
        for (int k = 1; k <= n; k++)
        {
            // 只更新还没有找到的最小权值
            if (!vis[k])
                dist[k] = min(dist[k], a[cur][k]);
        }
    }
    return sum;
}

int main(void)
{
    scanf("%d%d", &n, &m);
    memset(a, 0x3f, sizeof(a));
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }
    int value = prim(1);
    if (value >= INF)
        puts("impossible");
    else
        printf("%lld\n", sum);
    return 0;
}

void prim1(int g[][])
{
    // 初始化第一个点
    dist[1] = 0;    // 把点1加入集合S，点1在集合S中，将它到集合的距离初始化为0
    book[1] = true; // 表示点1已经加入到了S集合中
    // 用点1去更新dist[]
    for (int i = 2; i <= n; i++)
        dist[i] = min(dist[i], g[1][i]); 

    // 遍历剩下的点
    for (int i = 2; i <= n; i++)
    {
        int temp = INF; // 初始化距离
        int t = -1;     // 接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标。
        for (int j = 2; j <= n; j++)
        {
            if (!book[j] && dist[j] < temp) // 如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
            {
                temp = dist[j]; // 更新集合V到集合S的最小值
                t = j;          // 把点赋给t
            }
        }
        if (t == -1)
        {
            res = INF;
            return;
        }
        // 如果t==-1，意味着在集合V找不到边连向集合S，生成树构建失败，将res赋值正无穷表示构建失败，结束函数
        book[t] = true; // 如果找到了这个点，就把它加入集合S
        res += dist[t]; // 加上这个点到集合S的距离

        for (int j = 2; j <= n; j++)
            if (!book[j])
                dist[j] = min(dist[j], g[t][j]); // 用新加入的点更新dist[]
    }
}

class Solution
{
public:
    static bool cmp(vector<int> &x, vector<int> &y)
    { // 重载比较，按照边权递增
        return x[2] < y[2];
    }

    int miniSpanningTree(int n, int m, vector<vector<int>> &cost)
    {
        unordered_set<int> points; // 记录不重复的点
        int res = 0;
        sort(cost.begin(), cost.end(), cmp); // 排序得到最小值
        res += cost[0][2];                   // 首先将最小的边加入
        points.insert(cost[0][0]);
        points.insert(cost[0][1]);
        while (1)
        {
            if (points.size() == n) // 所有的点已连通
                break;
            for (auto iter = cost.begin(); iter != cost.end(); iter++)
            { // 从小到大遍历剩余的边
                // 这个边一个点在集合内，一个不在就加入
                if ((points.find((*iter)[0]) != points.end() && points.find((*iter)[1]) == points.end()) || (points.find((*iter)[1]) != points.end() && points.find((*iter)[0]) == points.end()))
                {
                    res += (*iter)[2];
                    points.insert((*iter)[0]);
                    points.insert((*iter)[1]);
                    cost.erase(iter); // 删除该边
                    break;
                }
            }
        }
        return res;
    }
};


int miniSpanningTree(int n, int m, vector<vector<int> >& cost) 
{
    // write code here
    bool bFlag[n] = {false};
    int nRes = 0;
    int nDis[n] = {INF};
    nDis[0] = 0;

    // 初始化第一个点
    bFlag[0] = true;
    for (int i = 1; i < n; i++)
    {
        nDis[i] = min(nDis[i], cost[0][i]);
    }

    for (int i = 1; i < n; i++)
    {
        int nTemp = INF;
        int nPos = -1;
        for (int j = 1; j < n; j++)
        {
            if (!bFlag[j] && temp > nDis[j])
            {
                nPos = j;
                nTemp = nDis[j];
            }
        }

        if (nPos == -1)
        {
            return -1;
        }

        nRes += nTemp;
        bFlag[nPos] = true;
        for (int j = 1; j < n; j++)
        {
            if (!bFlag[j])
            {
                nDis[j] = min(nDis[j], cost[0][j]);
            }
        }
    }

    return nRes;

}
```
#### 1、prim
```
```
#### 2、Kruskal
```
```
