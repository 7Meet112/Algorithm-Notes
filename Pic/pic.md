- [图的定义和术语](#图的定义和术语)
- [存储结构](#存储结构)
- [遍历算法](#遍历算法)
- [最小生成树](#最小生成树)

#### 图的定义和术语
   
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/hutouhuwei.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/ruduchudu.png)
 
#### 存储结构
   
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/basepic.png)

   - 数组表示（邻接矩阵）
     
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/lingjiejuzhen.png)
   - 邻接表
     
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/linjiebiao.png)
   - 十字链表

   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/shizilianbiao2.png)
   
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/shizilianbiao.png)
   
#### 遍历算法
   
   bfs dfs
   
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/dfsbfs2.png)

   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/dfsbfs.png)
#### 最小生成树
- prim
- 主要思想

从已知扩散寻找最小。它的实现方式和Dijkstra算法相似但稍微有所区别，Dijkstra是求单源最短路径，而每计算一个点需要对这个点重新更新距离，而prim不用更新距离。直接找已知点的邻边最小加入即可！
- 具体步骤

1.寻找图中任意点，以它为起点，它的所有边V加入集合(优先队列)q1,设置一个boolean数组bool[]标记该位置(边有两个点，每次加入没有被标记那个点的所有边)。

2.从集合q1找到距离最小的那个边v1并判断边是否存在未被标记的一点p ，如果p不存在说明已经确定过那么跳过当前边处理，如果未被标(访问)记那么标记该点p,并且与p相连的未知点(未被标记)构成的边加入集合q1， 边v1(可以进行计算距离之类，该边构成最小生成树) .

3.重复1，2直到q1为空，构成最小生成树 ！

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/prim1.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/prim2.png)

- kruskal
- 主要思想
  
先构造一个只含 n 个顶点、而边集为空的子图，把子图中各个顶点看成各棵树上的根结点，之后，从网的边集 E 中选取一条权值最小的边，若该条边的两个顶点分属不同的树，则将其加入子图，即把两棵树合成一棵树，反之，若该条边的两个顶点已落在同一棵树上，则不可取，而应该取下一条权值最小的边再试之。依次类推，直到森林中只有一棵树，也即子图中含有 n-1 条边为止。
- 具体步骤
  
1.将图中所有边对象(边长、两端点)依次加入集合(优先队列)q1中。初始所有点相互独立。

2.取出集合(优先队列)q1最小边，判断边的两点是否联通。

3.如果联通说明两个点已经有其它边将两点联通了，跳过，如果不连通，则使用union（并查集合并）将两个顶点合并，这条边被使用(可以储存或者计算数值)。

4.重复2，3操作直到集合（优先队列）q1为空。此时被选择的边构成最小生成树。

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/kruskal1.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/kruskal2.png)

