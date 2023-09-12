- [遍历二叉树](#遍历二叉树)
- [线索二叉树](#线索二叉树)
- [哈夫曼树](#哈夫曼树)
- [树和森林的转换](#树和森林的转换)

##### 遍历二叉树
```

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void preTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        ans.push_back(root->val);
        preTree(root->left);
        preTree(root->right);
    }

    void midTree(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
        {
            return;
        }
        midTree(pRoot->left);
        ans.push_back(pRoot->val);
        midTree(pRoot->right);
    }

    void after(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
        {
            return;
        }

        after(pRoot->left);
        after(pRoot->right);
        ans.push_back(pRoot->val);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        preTree(root);
        // midTree(root);
        // after(root);
        return ans;
    }

    vector<int> ans;
};
```
##### 线索二叉树

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/tree1.png)

##### 哈夫曼树

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/tree2.png)

##### 树和森林的转换

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/tree4.png)

![Image text](https://github.com/7Meet112/Algorithm-Notes/blob/main/image/tree5.png)
