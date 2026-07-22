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

// optimal
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int>> q;
        int ans = 0;                   
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int mn = q.front().second;
            int first = 0;
            int last = 0;
            for (int i = 0; i < size; i++)
            {
                int curInd = q.front().second - mn;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curInd;
                if (i == size - 1)
                    last = curInd;
                if (node->left)
                {
                    q.push({node->left, (long long)curInd * 2 + 1});
                }
                if (node->right)
                {
                    q.push({node->right, (long long)curInd * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};