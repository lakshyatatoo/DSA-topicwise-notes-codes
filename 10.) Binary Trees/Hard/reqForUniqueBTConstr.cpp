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

// inorder with anyome else will always form a unique bianry tree becauusue it stores the left and right info unlike others
// and 2 same also cant be it inorder
class Solution
{
public:
    bool isPossible(int a, int b)
    {
        // preorder - 1, inorder - 2, postorder - 3
        if (a == b)
            return false;
        if (a == 2 || b == 2)
            return true;
        else
            return false;
    }
};