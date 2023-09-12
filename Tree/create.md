```

/*
    A B # # C D # E # # F # #
    4
    
    A B C # # # D # # 
    3
*/

#include "iostream"
#define Max 100
using namespace std;

typedef struct TreeNode {
    char data;
    struct TreeNode *lc, *rc;
} *Tree;

void Create(Tree &T) {
    char x;
    cin >> x;
    if (x == '#')
        T = nullptr;
    else {
        if (!(T = (Tree) malloc(sizeof(TreeNode))))
            exit(-1);
        T->data = x;
        Create(T->lc);
        Create(T->rc);
    }
}

int main() {
    Tree T = nullptr;
    Create(T);
    return 0;
}
```
