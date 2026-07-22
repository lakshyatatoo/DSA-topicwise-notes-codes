#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void inOrder(vector<int> &ans, TreeNode *node)
    {
        if (node == nullptr)
            return;

        inOrder(ans, node->left);
        ans.push_back(node->val);
        inOrder(ans, node->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inOrder(ans, root);
        return ans;
    }
};