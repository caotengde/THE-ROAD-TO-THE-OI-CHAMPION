# 问题2：二叉树遍历（Binary Tree Traversal）

## 难度：中等

## 问题描述

给定一棵二叉树，请你输出它的前序遍历、中序遍历和后序遍历的结果。

### 输入格式
- 第一行包含一个整数 n，表示二叉树的节点数
- 接下来 n 行，每行包含三个整数 val, left, right，分别表示节点值、左孩子编号和右孩子编号
  - 编号从1到n，0表示空节点
  - 第一个节点（编号1）为根节点

### 输出格式
- 第一行输出前序遍历结果
- 第二行输出中序遍历结果
- 第三行输出后序遍历结果

### 数据范围
- 1 ≤ n ≤ 1000
- 1 ≤ val ≤ 1000

## 样例

### 样例输入
```
7
1 2 3
2 4 5
3 6 7
4 0 0
5 0 0
6 0 0
7 0 0
```

### 样例输出
```
1 2 4 5 3 6 7
4 2 5 1 6 3 7
4 5 2 6 7 3 1
```

## 解题思路

### 二叉树遍历方式

1. **前序遍历（Pre-order）**：根 -> 左 -> 右
2. **中序遍历（In-order）**：左 -> 根 -> 右
3. **后序遍历（Post-order）**：左 -> 右 -> 根

### 实现方法

- **递归实现**：简洁直观
- **迭代实现**：使用栈模拟递归过程

## 参考代码

### C++ 解法（递归）

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    int left, right;
};

vector<TreeNode> tree;
vector<int> preorder, inorder, postorder;

void preOrder(int node) {
    if (node == 0) return;
    preorder.push_back(tree[node].val);
    preOrder(tree[node].left);
    preOrder(tree[node].right);
}

void inOrder(int node) {
    if (node == 0) return;
    inOrder(tree[node].left);
    inorder.push_back(tree[node].val);
    inOrder(tree[node].right);
}

void postOrder(int node) {
    if (node == 0) return;
    postOrder(tree[node].left);
    postOrder(tree[node].right);
    postorder.push_back(tree[node].val);
}

int main() {
    int n;
    cin >> n;
    
    tree.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
    }
    
    preOrder(1);
    inOrder(1);
    postOrder(1);
    
    // 输出前序遍历
    for (int i = 0; i < preorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << preorder[i];
    }
    cout << endl;
    
    // 输出中序遍历
    for (int i = 0; i < inorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << inorder[i];
    }
    cout << endl;
    
    // 输出后序遍历
    for (int i = 0; i < postorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << postorder[i];
    }
    cout << endl;
    
    return 0;
}
```

### Python 解法

```python
class TreeNode:
    def __init__(self, val=0, left=0, right=0):
        self.val = val
        self.left = left
        self.right = right

def pre_order(tree, node, result):
    if node == 0:
        return
    result.append(tree[node].val)
    pre_order(tree, tree[node].left, result)
    pre_order(tree, tree[node].right, result)

def in_order(tree, node, result):
    if node == 0:
        return
    in_order(tree, tree[node].left, result)
    result.append(tree[node].val)
    in_order(tree, tree[node].right, result)

def post_order(tree, node, result):
    if node == 0:
        return
    post_order(tree, tree[node].left, result)
    post_order(tree, tree[node].right, result)
    result.append(tree[node].val)

# 输入
n = int(input())
tree = [None] * (n + 1)

for i in range(1, n + 1):
    val, left, right = map(int, input().split())
    tree[i] = TreeNode(val, left, right)

# 遍历
preorder = []
inorder = []
postorder = []

pre_order(tree, 1, preorder)
in_order(tree, 1, inorder)
post_order(tree, 1, postorder)

# 输出
print(' '.join(map(str, preorder)))
print(' '.join(map(str, inorder)))
print(' '.join(map(str, postorder)))
```

## 知识点
- 二叉树基本概念
- 递归思想
- 树的遍历算法
- DFS（深度优先搜索）

## 扩展思考
1. 如何使用栈实现非递归的遍历？
2. 层序遍历（BFS）如何实现？
3. 给定前序和中序遍历，能否重建二叉树？
4. 如何判断两棵树是否相同？
