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

// approach 1 using queue and a map for vertical + level
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
// approach 2 using a map and a vector
class Solution
{
public:
    vector<tuple<int, int, int>> nodes;
    void traverse(TreeNode *root, int x, int y)
    {
        if (root == nullptr)
            return;
        nodes.push_back({x, y, root->val});
        traverse(root->left, x - 1, y + 1);
        traverse(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        nodes.clear();
        vector<vector<int>> ans;
        if (!root)
            return ans;
        traverse(root, 0, 0);
        sort(nodes.begin(), nodes.end());

        int prevCol = INT_MIN;
        for (auto [x, y, val] : nodes)
        {
            if (x != prevCol)
            {
                ans.push_back({});
                prevCol = x;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};