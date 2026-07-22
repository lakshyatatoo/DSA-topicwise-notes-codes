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
    void postOrder(vector<int> &ans, TreeNode *node)
    {
        if (node == nullptr)
            return;

        postOrder(ans, node->left);
        postOrder(ans, node->right);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrder(ans, root);
        return ans;
    }
};