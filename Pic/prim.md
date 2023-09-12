```
	// prim 算法求最小生成树 
	
	#include <cstdio>
	#include <string>
	#include <cstring>
	#include <iostream>
	#include <algorithm>
	
	#define INF 0x3f3f3f3f
	
	using namespace std;
	
	const int maxn = 505;
	
	int a[maxn][maxn];
	
	int vis[maxn],dist[maxn];
	
	int n,m;
	
	int u,v,w;
	
	long long sum = 0;
	
	int prim(int pos) {
		dist[pos] = 0;
		// 一共有 n 个点,就需要 遍历 n 次,每次寻找一个权值最小的点,记录其下标
		for(int i = 1; i <= n; i ++) {
			int cur = -1;
			for(int j = 1; j <= n; j ++) {
				if(!vis[j] && (cur == -1 || dist[j] < dist[cur])) {
					cur = j;
				}
			}
			// 这里需要提前终止
			if(dist[cur] >= INF) return INF;
			sum += dist[cur];
			vis[cur] = 1;
			for(int k = 1; k <= n; k ++) {
			    // 只更新还没有找到的最小权值
				if(!vis[k]) dist[k] = min(dist[k],a[cur][k]);
			}
		}
		return sum;
	}
	
	int main(void) {
		scanf("%d%d",&n,&m);
		memset(a,0x3f,sizeof(a));
		memset(dist,0x3f,sizeof(dist));
		for(int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&u,&v,&w);
			a[u][v] = min(a[u][v],w);
			a[v][u] = min(a[v][u],w);
		}
		int value = prim(1);
		if(value >= INF) puts("impossible");
		else printf("%lld\n",sum);
		return 0;
	} 

```
