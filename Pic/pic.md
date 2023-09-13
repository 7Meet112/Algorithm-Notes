1. 图的定义和术语
   
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/hutouhuwei.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/ruduchudu.png)
 
2. 存储结构
   
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/basepic.png)

   - 数组表示（邻接矩阵）
     
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/lingjiejuzhen.png)
   - 邻接表
     
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/linjiebiao.png)
   - 十字链表

   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/shizilianbiao2.png)
   
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/shizilianbiao.png)
   
4. 遍历算法
   
   bfs dfs
   
   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/dfsbfs2.png)

   ![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/dfsbfs.png)
6. 最小生成树
   1. prim
      
   2. kruskal
      先构造一个只含 n 个顶点、而边集为空的子图，把子图中各个顶点看成各棵树上的根结点，之后，从网的边集 E 中选取一条权值最小的边，若该条边的两个顶点分属不同的树，则将其加入子图，即把两棵树合成一棵树，反之，若该条边的两个顶点已落在同一棵树上，则不可取，而应该取下一条权值最小的边再试之。依次类推，直到森林中只有一棵树，也即子图中含有 n-1 条边为止。

