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

// brute force approach
class Solution
{
public:
    void preorder(TreeNode *root, vector<string> &ans, string s)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(s + to_string(root->val));
            return;
        }
        if (root->left)
            preorder(root->left, ans, s + to_string(root->val));
        if (root->right)
            preorder(root->right, ans, s + to_string(root->val));
    }
    int sumNumbers(TreeNode *root)
    {
        vector<string> ans;
        preorder(root, ans, "");
        int sum = 0;
        for (string x : ans)
        {
            sum = sum + stoi(x);
        }
        return sum;
    }
};

// optimal

class Solution
{
public:
    int summer(TreeNode *root, int s)
    {
        if (!root)
            return 0;
        s = s * 10 + root->val;
        if (!root->left && !root->right)
            return s;
        return summer(root->left, s) + summer(root->right, s);
    }
    int sumNumbers(TreeNode *root)
    {
        int s = 0;
        return summer(root, s);
    }
};