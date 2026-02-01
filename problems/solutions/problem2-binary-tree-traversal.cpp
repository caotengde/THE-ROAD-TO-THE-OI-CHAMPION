/*
 * 问题2：二叉树遍历
 * 递归实现前序、中序、后序遍历
 */

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
