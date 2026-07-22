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
    void preOrder(vector<int> &ans, TreeNode *node)
    {
        if (node == nullptr)
            return;

        ans.push_back(node->val);
        preOrder(ans, node->left);
        preOrder(ans, node->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preOrder(ans, root);
        return ans;
    }
};