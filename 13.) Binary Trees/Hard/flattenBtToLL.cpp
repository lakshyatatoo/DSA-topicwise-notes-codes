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

// approaach 1 interview one recrusive a reverse preorder approach so we know info
// not storing root at first but right to right to right
class Solution
{
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// approaach 2 iterative approach using stack
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);

            if (!st.empty())
            {
                cur->right = st.top();
                cur->left = nullptr;
            }
        }
    }
};

// approach 3 most optimal
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode *prev = cur->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};