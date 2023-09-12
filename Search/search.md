- [顺序查找](#顺序查找)
- [二分查找](#二分查找)
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
1. 哈希表

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi1.png)
2. 哈希函数的构造

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi3.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi2.png)
3. 哈希冲突解决
![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/haxi1.png)
