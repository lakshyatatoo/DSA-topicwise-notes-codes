#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> res;
    void path(Node *root, vector<int> ans)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(ans);
            return;
        }

        if (root->left)
            path(root->left, ans);
        if (root->right)
            path(root->right, ans);
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<int> ans;
        path(root, ans);
        return res;
    }
};