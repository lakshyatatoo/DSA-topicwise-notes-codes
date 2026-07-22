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
    void mapParent(TreeNode *root, int start,
                   unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *&target)
    {
        if (root == nullptr)
            return;

        if (root->val == start)
            target = root;
        if (root->left)
        {
            mp[root->left] = root;
        }
        if (root->right)
        {
            mp[root->right] = root;
        }
        mapParent(root->left, start, mp, target);
        mapParent(root->right, start, mp, target);
    }
    int findMaxDist(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        vis[target] = true;
        int maxi = 0;
        q.push(target);
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left && !vis[node->left])
                {
                    flag = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right])
                {
                    flag = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (mp[node] && !vis[mp[node]])
                {
                    flag = true;
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
            if (flag)
                maxi++;
        }
        return maxi;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        TreeNode *target = nullptr;
        mapParent(root, start, mp, target);
        int maxi = findMaxDist(target, mp);
        return maxi;
    }
};