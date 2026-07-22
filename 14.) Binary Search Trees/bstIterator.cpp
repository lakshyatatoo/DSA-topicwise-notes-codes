#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// brute vector stores all elements in sorted order
class BSTIterator
{
public:
    vector<int> ans;
    int i;
    BSTIterator(TreeNode *root)
    {
        inorder(root);
        i = 0;
    }

    int next()
    {
        int x = 0;
        if (i < ans.size())
            x = ans[i++];
        return x;
    }

    bool hasNext()
    {
        return i < ans.size();
    }
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
};

// optimal
// tc: O(1) amortized, sc: O(h)
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root) { pushA(root); }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushA(temp->right);
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
    void pushA(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};