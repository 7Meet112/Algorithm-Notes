- [顺序查找](#顺序查找)
- [二分查找](#二分查找)
- [哈希查找](#哈希查找)
  - [哈希表](#哈希表)
  - [哈希函数的构造](#哈希函数的构造)
  - [哈希冲突解决](#哈希冲突解决)
  - [哈希查找](#哈希查找)

#### 顺序查找
从表中最后一个记录开始，逐个进行记录的关键字和给定值的比较，若某个记录的关键字和给定值比较相等，则查找成功，找到所查记录，反之，若直至第一个记录，其关键字和给定值比较都不相等，则表明表中没有所查记录，查找不成功。
```
int Search(SStable ST, KeyType key)
{
    ST.elem[0].key = key;//哨兵
    for (i = ST.length; !EQ(ST.elem[i].key, key); --i)//从后往前
    return i;//找不到时返回0
}
```
#### 二分查找
```
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // write code here
        int nSize = nums.size();
        if (nSize <= 0)
            return -1;
        int nL = 0, nR = nSize - 1, nMid = 0;
        while (nL <= nR)
        {
            nMid = (nL + nR) / 2;
            if (nums[nMid] == target)
                return nMid;
            else if (nums[nMid] < target)
                nL = nMid + 1;
            else
                nR = nMid - 1;
        }
        return -1;
    }
};
```
#### 哈希查找
##### 哈希表

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi1.png)
##### 哈希函数的构造

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi3.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi2.png)
##### 哈希冲突解决
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi4.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi5.png)
##### 哈希查找

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haix6.png)

```
#include"stdio.h"
#define M 6
#define P (M+1)
typedef struct HashTable
{
	int key;      //关键字 
	int EmptyFlag;//占用（冲突）标志，0表示没被占用，1表示被占用 
}HashTable;

void CreateHashTable( HashTable *tbl, int *data, int m, int p );
int SearchHashTable( HashTable *tbl, int key, int p );

int main()
{
	HashTable HashTbl[P];
	int data[M] = { 10, 8, 14, 15, 20, 31 };
	int i, loc;
	printf( "初始数据：\n" );
	for( i=0; i<M; i++ )
	{
		printf( "data[%d] = %5d\n", i, data[i] );
	}
	printf( "\n" );
	CreateHashTable( HashTbl, data, M, P );
	printf( "哈希表：  \n" );
	for( i=0; i<M; i++ )
	{
		printf( "tbl[%d] = %5d\n", i, HashTbl[i].key );
	}
	printf( "\n" );
	for( i=0; i<M; i++ )
	{
		loc = SearchHashTable( HashTbl, data[i], P );
		printf( "%5d 's loc = %5d\n", data[i], loc );
	}
	
	return 0;
}
void CreateHashTable( HashTable *tbl, int *data, int m, int p )
{
	int i, addr, k;
	for( i=0; i<p; i++ ) //把哈希表被占用标志置为0 
	{
		tbl[i].EmptyFlag = 0;
	}
	for( i=0; i<m; i++ )
	{
		addr = data[i] % p;//计算哈希地址 
		k = 0;//记录冲突次数 
		while( k++ < p )
		{
			if( tbl[addr].EmptyFlag == 0 )
			{
				tbl[addr].EmptyFlag = 1;//表示该位置已经被占用 
				tbl[addr].key   = data[i];
				break;
			}
			else
			{
				addr =  ( addr + 1 ) % p; //处理冲突 
			}
		}	
	}
}

int SearchHashTable( HashTable *tbl, int key, int p )
{
	int addr, k, loc;//loc表示查找位置下标，如果为0则表示查找失败 
	addr = key % P;//计算Hash地址 
	loc = -1; 
	k = 0;//记录冲突次数 
	while( k++ < p )
	{
		if( tbl[addr].key == key )
		{
			loc = addr;
			break;
		}
		else
		{
			addr =  ( addr + 1 ) % p; //处理冲突 
		}	
	}
	return loc;
}

```
