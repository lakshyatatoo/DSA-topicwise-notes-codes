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

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> preOrder;
        if (root == nullptr)
            return preOrder;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            if (root->right != nullptr)
                st.push(root->right);
            if (root->left != nullptr)
                st.push(root->left);
        }
        return preOrder;
    }
};