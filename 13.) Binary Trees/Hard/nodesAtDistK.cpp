#include <bits/stdc++.h>
using namespace std;

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
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        if (root == nullptr)
            return;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;
        markParents(root->left, mp);
        markParents(root->right, mp);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> result;
        unordered_map<TreeNode *, bool> visited;
        unordered_map<TreeNode *, TreeNode *> mp;
        markParents(root, mp);
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (level++ == k)
                break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (mp[node] && !visited[mp[node]])
                {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
        }
        while (!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};